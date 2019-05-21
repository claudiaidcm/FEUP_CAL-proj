#ifndef CONTAINER_H_
#define CONTAINER_H_

#include "node.h"

class Container : public Node{
	bool full; //if container is full or not
	float volume; //container volume
	char type; //type of trash disposed to this container
public:
	double dist; //distance between a particular container to the nearest treatment station
	int pos; //position of the container in the vector it is contained

	Container();
	Container(string ID, float lat, float lon);
	Container(string ID, float lat, float lon, bool full, float volume, char type);
	Container(Node n, bool full, float volume, char type);

	Container & setFull(bool full);
	Container & setVolume(float volume);
	Container & setType(char type);
	float getVolume();
	char getType()const;
	Node getNode();

	bool isFull();
};

struct compareContainerPointers {
	bool const operator()(Container *c1, Container *c2) const {
		return c1->dist < c2->dist;
	}
};

#endif /* CONTAINER_H_ */

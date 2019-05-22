#ifndef CONTAINER_H_
#define CONTAINER_H_

#include "Node.h"

class Container: public Node {

private:
	bool full = false; //indicates  whether the container is full or not
	float capacity = 0; //container maximum capacity
	char type = '0'; //type of trash disposed to this container
	double dist = 0; //distance between a particular container to the nearest treatment station
	int pos = 0; //position of the container in the vector of containers

public:
	Container();
	Container(string ID, float lat, float lon);
	Container(string ID, float lat, float lon, bool full, float capacity,
			char type);
	Container(Node n, bool full, float capacity, char type);

	void setFull(bool full);
	void setCapacity(float capacity);
	void setType(char type);

	float getCapacity();
	char getType() const;
	int getPos();
	double getDistance();
	Node getNode();

	bool isFull();
};

struct compareContainers {
	bool const operator()(Container *c1, Container *c2) const {
		return c1->getDistance() < c2->getDistance();
	}
};

#endif /* CONTAINER_H_ */

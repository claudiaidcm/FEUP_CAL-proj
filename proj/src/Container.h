#ifndef CONTAINER_H_
#define CONTAINER_H_

#include "Node.h"
#include "Graph.h"

class Container: public Node {

private:
	Vertex<Node> *node;
	bool full = false; //indicates  whether the container is full or not
	float capacity = 0; //container maximum capacity
	char type; //type of trash disposed to this container

public:
	Container();
	Container(Vertex<Node> * node, bool full, float capacity, char type);

	void setFull(bool full);
	void setCapacity(float capacity);
	void setType(char type);

	float getCapacity();
	char getType() const;
	Vertex<Node> *getNode();
	bool isFull();
};

#endif /* CONTAINER_H_ */

#include "Container.h"

Container::Container():Node() {}

Container::Container(Vertex<Node> * node, bool full, float capacity, char type):full(full), capacity(capacity), type(type), node(node)
{}

void Container::setFull(bool full)
{
	this->full = full;
}

void Container::setCapacity(float capacity)
{
	this->capacity = capacity;
}

void Container::setType(char type)
{
	this->type = type;
}

float Container::getCapacity()
{
	return capacity;
}

char Container::getType() const
{
	return type;
}

Vertex<Node>* Container::getNode() {
	return this->node;
}

bool Container::isFull()
{
	return full;
}




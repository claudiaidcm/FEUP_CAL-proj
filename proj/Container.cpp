#include "Container.h"

Container::Container():Node() {}

Container::Container(string ID, float lat, float lon):Node(ID, lat, lon) {}

Container::Container(string ID, float lat, float lon, bool full, float capacity, char type)
	:Node(ID, lat, lon), full(full), capacity(capacity), type(type){}

Container::Container(Node n, bool full, float capacity, char type):full(full), capacity(capacity), type(type)
{
	this->ID = n.getID();
	this->lat = n.getLat();
	this->lon = n.getLon();
}

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

Node Container::getNode()
{
	return Node(ID, lat, lon);
}

bool Container::isFull()
{
	return full;
}




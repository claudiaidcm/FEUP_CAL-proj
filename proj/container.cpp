#include "container.h"

Container::Container():Node() {}

Container::Container(string ID, float lat, float lon):Node(ID, lat, lon) {}

Container::Container(string ID, float lat, float lon, bool full, float volume, char type)
	:Node(ID, lat, lon), full(full), volume(volume), type(type) {}

Container::Container(Node n, bool full, float volume, char type):full(full), volume(volume), type(type)
{
	this->ID = n.getID();
	this->lat = n.getLat();
	this->lon = n.getLon();
}

Container & Container::setFull(bool full)
{
	this->full = full;
	return *this;
}

Container & Container::setVolume(float volume)
{
	this->volume = volume;
	return *this;
}

Container & Container::setType(char type)
{
	this->type = type;
	return *this;
}

float Container::getVolume()
{
	return volume;
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




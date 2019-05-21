#include "garbage_truck.h"

Truck::Truck(){}

Truck::Truck(Node central, float volume, char type):central(central),volume(volume),type(type) {}

Truck & Truck::setCentral(Node central)
{
	this->central = central; return *this;
}

Truck & Truck::setVolume(float volume)
{
	this->volume = volume; return *this;
}

Truck & Truck::setType(char type)
{
	this->type = type;
	return *this;
}

Node Truck::getCentral()
{
	return central;
}

float Truck::getVolume()
{
	return volume;
}

char Truck::getType() const
{
	return type;
}

Truck & Truck::addTrash(float value)
{
	this->volume += value; return *this;
}




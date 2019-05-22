#include "Garbage_truck.h"

Truck::Truck(){}

Truck::Truck(Node central, float capacity, char type):central(central),capacity(capacity),type(type) {}

void Truck::setCentral(Node central)
{
	this->central = central;
}

void Truck::setFreeVolume(float freeVolume)
{
	this->freeVolume = freeVolume;
}

void Truck::setType(char type)
{
	this->type = type;
}

Node Truck::getCentral()
{
	return central;
}

float Truck::getFreeVolume()
{
	return freeVolume;
}

char Truck::getType() const
{
	return type;
}

void Truck::addTrash(float value)
{
	this->freeVolume -= value;
}




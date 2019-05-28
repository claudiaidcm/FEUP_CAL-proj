#include "Garbage_truck.h"

Truck::Truck(double centralId, float capacity, char type):centralId(centralId),capacity(capacity),type(type) {
	freeVolume = capacity;
}

void Truck::setFreeVolume(float freeVolume)
{
	this->freeVolume = freeVolume;
}

void Truck::setType(char type)
{
	this->type = type;
}

float Truck::getCapacity() {
	return capacity;
}

double Truck::getCentralId()
{
	return centralId;
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

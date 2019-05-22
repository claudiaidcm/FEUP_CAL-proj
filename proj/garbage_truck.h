#ifndef GARBAGE_TRUCK_H_
#define GARBAGE_TRUCK_H_

#include "Node.h"

class Truck{
	Node central;
	bool full = false;//indicates whether the truck is full or not
	float capacity = 0;
	float freeVolume = 0;
	char type = '0'; //residue type

public:
	Truck();
	Truck(Node central, float capacity, char type);

	void setCentral(Node central);
	void setFreeVolume(float volume);
	void setType(char type);
	void setCapacity(float capacity);
	void setFull(bool full);

	float getCapacity();
	Node getCentral();
	float getFreeVolume();
	char getType()const;

	bool isFull();

	void addTrash(float value);
};

#endif /* GARBAGE_TRUCK_H_ */

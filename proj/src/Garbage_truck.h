#ifndef GARBAGE_TRUCK_H_
#define GARBAGE_TRUCK_H_

#include "Node.h"

class Truck{
	int centralId;
	bool full = false;//indicates whether the truck is full or not
	float capacity;
	float freeVolume;
	char type = '0'; //residue type

public:
	Truck(double centralId, float capacity, char type);

	void setFreeVolume(float volume);
	void setType(char type);
	void setCapacity(float capacity);
	void setFull(bool full);

	double getCentralId();
	float getCapacity();
	float getFreeVolume();
	char getType()const;

	bool isFull();

	void addTrash(float value);
};

#endif /* GARBAGE_TRUCK_H_ */

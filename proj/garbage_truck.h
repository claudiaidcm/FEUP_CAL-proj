#ifndef GARBAGE_TRUCK_H_
#define GARBAGE_TRUCK_H_

#include "node.h"

class Truck{
	Node central;
	float volume;
	char type; //type of trash
public:
	Truck();
	Truck(Node central, float volume, char type = 'i');
	Truck & setCentral(Node central);
	Truck & setVolume(float volume);
	Truck & setType(char type);
	Node getCentral();
	float getVolume();
	char getType()const;

	Truck & addTrash(float value);
};



#endif /* GARBAGE_TRUCK_H_ */

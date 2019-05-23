#ifndef TREATMENT_STATION_H_
#define TREATMENT_STATION_H_

#include "Node.h"

class TreatmentStation: public Node{
protected:
	char type='0'; //type of trash that is treated in a particular station
public:
	TreatmentStation();
	TreatmentStation(Node n);
	TreatmentStation(string ID, float lat, float lon);
	TreatmentStation(string ID, float lat, float lon, char type);

	TreatmentStation & setType(char t);
	char getType()const;
	Node getNode();
};



#endif /* TREATMENT_STATION_H_ */

#ifndef TREATMENT_STATION_H_
#define TREATMENT_STATION_H_

#include "Node.h"
#include "Graph.h"

class TreatmentStation: public Node{
protected:
	Vertex<Node> *node;
	char type; //type of trash that is treated in a particular station
public:
	TreatmentStation();
	TreatmentStation(Vertex<Node> * node, char type);

	TreatmentStation & setType(char t);
	char getType()const;
};



#endif /* TREATMENT_STATION_H_ */

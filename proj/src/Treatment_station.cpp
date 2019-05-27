#include "Treatment_station.h"

#include "Node.h"

using namespace std;

TreatmentStation::TreatmentStation(Vertex<Node> * node, char t):node(node), type(t){}

char TreatmentStation::getType()const {return type;}

void TreatmentStation::setType(char t){
	this->type = t;
}

Vertex<Node>* TreatmentStation::getNode() {
	return this->node;
}




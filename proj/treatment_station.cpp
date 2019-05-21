#include "treatment_station.h"
#include "node.h"

using namespace std;

TreatmentStation::TreatmentStation():Node(), type('a') { }

TreatmentStation::TreatmentStation(Node n) {
	ID = n.getID();
	lat = n.getLat();
	lon = n.getLon();
}

TreatmentStation::TreatmentStation(string ID, float lat, float lon):Node(ID, lat, lon) {}

TreatmentStation::TreatmentStation(string ID, float lat, float lon, char t){}

char TreatmentStation::getType()const {return type;}

TreatmentStation & TreatmentStation::setType(char t){
	this->type = t;
	return *this;
}

Node TreatmentStation::getNode() {
	return Node(ID, lat, lon);
}





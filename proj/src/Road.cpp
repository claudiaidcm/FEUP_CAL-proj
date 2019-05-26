#include "Road.h"

Road::Road():Road("0","InvalidName",false){}

Road::Road(string ID, string name, bool bothWays):ID(ID), bothWays(bothWays) {
	if (name == "")
		this->name = "InvalidName";
	else
		this->name = name;
}

Road * Road::findRoadByID(vector<Road *> roads, string ID) {
	for (auto road : roads)
		if (road->ID == ID)
			return road;
	return nullptr;
}

ostream & operator<<(ostream & os, const Road & r) {
	os << "{ID: "<< r.ID << ", name: " << r.name << ", bothWays: " << (r.bothWays ? "True" : "False")  << "}";
	return os;
}




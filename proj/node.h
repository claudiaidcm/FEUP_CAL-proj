#pragma once

#include <cmath>
#include <string>

#define earthRadiusKm 6371.0

class Node {
protected:
	double lat, lon;	//radian values
	int id;
public:
	Node();
	Node(int id);
	Node(int id, double lat, double lon);
	double getLat();
	double getLon();
	int getId();
	Node & setLat(double lat);
	Node & setLon(double lon);
	Node & setId(int id);

	//Returns the distance between two points on the Earth.
	double distance(Node end);
};

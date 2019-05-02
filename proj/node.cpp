#include "node.h"

double Node::getLat() {return lat;}

double Node::getLon() {return lon;}

int Node::getId() {return id;}

Node & Node::setLat(double lat) { this->lat = lat; return *this; }

Node & Node::setLon(double lon) { this->lon = lon; return *this;}

Node & Node::setId(int id) {this->id = id; return *this;}

double Node::distance(Node end) {
	double u, v;
	u = sin((end.lat - lat) / 2);
	v = sin((end.lon - lon) / 2);
	return 1000 * 2.0 * earthRadiusKm * asin(sqrt(u * u + cos(lat) * cos(end.lat) * v * v));//returns the distance in meters
}





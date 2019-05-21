#include "node.h"

Node::Node():Node("",0,0) {}

Node::Node(string ID, double lat, double lon):ID(ID),lat(lat),lon(lon) {}

Node::Node(string ID):ID(ID) {}

Node & Node::setLat(double lat)
{
	this->lat = lat; return *this;
}

Node & Node::setLon(double lon)
{
	this->lon = lon; return *this;
}

Node & Node::setID(string ID)
{
	this->ID = ID; return *this;
}

double Node::getLat()
{
	return lat;
}

double Node::getLon()
{
	return lon;
}

string Node::getID()
{
	return ID;
}

double Node::distance(Node end)
{
	double u, v;
	u = sin((end.lat - lat) / 2);
	v = sin((end.lon - lon) / 2);
	return 1000 * 2.0 * Earth_Radius * asin(sqrt(u * u + cos(lat) * cos(end.lat) * v * v));//returns the distance in meters
}

bool Node::operator==(const Node & n) const
{
	return ID == n.ID;
}

bool Node::operator!=(const Node & n) const
{
	return !this->operator==(n);
}

ostream & operator<<(ostream & os, const Node & n)
{
	os << "{ID: " << n.ID << ", lat: " << n.lat << ", lon: " << n.lon << "}";
	return os;
}




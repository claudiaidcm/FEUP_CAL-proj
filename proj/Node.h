#ifndef NODE_H_
#define NODE_H_

#include <cmath>
#include <string>
#include <ostream>

using namespace std;

#define PI 3.1415926536
#define Earth_Radius 6371.0

class Node {
protected:
	string ID;
	double lat, lon; //id, latitude and longitude respectively
public:
	Node();
	Node(string ID);
	Node(string ID, double lat, double lon);
	Node & setLat(double lat);
	Node & setLon(double lon);
	Node & setID(string ID);
	double getLat();
	double getLon();
	string getID();

	double distance(Node end); //returns the distance in meters between two nodes (relatively to the Earth)

	bool operator==(const Node & n) const;

	bool operator!=(const Node & n) const;

	friend ostream& operator<<(ostream& os, const Node& n);
};



#endif /* NODE_H_ */

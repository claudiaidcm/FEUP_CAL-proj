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
	int id;
	double x, y; //id, latitude and longitude respectively
public:
	Node();
	Node(int id);
	Node(int id, double x, double y);
	void setX(double x);
	void setY(double y);
	void setId(int id);
	double getX();
	double getY();
	int getId();

	double distance(Node end); //returns the distance in meters between two nodes (relatively to the Earth)

	bool operator==(const Node & n) const;

	bool operator!=(const Node & n) const;

	friend ostream& operator<<(ostream& os, const Node& n);
};



#endif /* NODE_H_ */

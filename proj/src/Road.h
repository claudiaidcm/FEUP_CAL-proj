#ifndef ROAD_H_
#define ROAD_H_

#include <string>
#include <vector>
#include <ostream>

#include "Node.h"
#include "Graph.h"

using namespace std;

class Road {
public:
	string id;
	bool bothWays;
	vector<Vertex<Node>*> form;

	Road();
	Road(string id, bool bothWays, vector<Vertex<Node>*> form);
};

#endif /* ROAD_H_ */

#ifndef SRC_MAP_CREATOR_H_
#define SRC_MAP_CREATOR_H_

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <string>
#include <fstream>
#include <math.h>
#include <sstream>

using namespace std;

#include "Graph.h"
#include "Node.h"
#include "Road.h"
#include "graphviewer.h"
#include "Container.h"
#include "Treatment_Station.h"

class map_creator {

private:
	Graph<Node> graph;
	vector<Node> nodes;
	GraphViewer *gv;
	vector<Container> containers;
	vector<TreatmentStation> stations;

public:
	void getNodes(string nodes_file);
	void getEdges(string edges_file);
	void getTags(string tags_file);

};

#endif /* SRC_MAP_CREATOR_H_ */

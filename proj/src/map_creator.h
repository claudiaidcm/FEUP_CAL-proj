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
	vector<Road> roads;
	GraphViewer *gv;
	vector<Container> containers;
	vector<TreatmentStation> stations;
	vector<Vertex<Node>*> transfer_stations;

public:
	map_creator();
	void showGraph();
	void getNodes(string nodes_file);
	void getEdges(string edges_file);
	void getTags(string tags_file);
	bool isContainer(int idNo);
	bool isLandFill (int idNo);
	bool isRecyclingContainer (int idNo);
	bool isRecyclingStation(int idNo);
	bool isTransferStation(int idNo);

};

#endif /* SRC_MAP_CREATOR_H_ */

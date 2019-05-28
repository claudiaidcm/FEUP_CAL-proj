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
#include <Algorithm>
#include <iostream>
#include <chrono>

using namespace std;
using namespace chrono;

#include "Graph.h"
#include "Node.h"
#include "Road.h"
#include "graphviewer.h"
#include "Container.h"
#include "Treatment_Station.h"
#include "Garbage_truck.h"

class map_creator {

private:
	Graph<Node> graph;
	vector<Node> nodes;
	vector<Road> roads;
	GraphViewer *gv;
	vector<Container> containers;
	vector<TreatmentStation> treatment_stations;
	vector<Vertex<Node>*> transfer_stations;
	vector<Truck> trucks;

public:
	map_creator();
	void setGraph(Graph<Node> t) {
		graph = t;
	}
	;
	void showGraph();
	void getNodes(string nodes_file);
	void getEdges(string edges_file);
	void getTags(string tags_file);
	Graph<Node> getGraph() {
		return graph;
	}
	;
	Node getNodeByID(int id);
	bool isContainer(int idNo);
	bool isLandFill(int idNo);
	bool isRecyclingContainer(int idNo);
	bool isRecyclingStation(int idNo);
	bool isTransferStation(int idNo);
	void addTruck(Truck t) {
		trucks.push_back(t);
	}
	;
	Container searchContainer(double id);
	Node closestTreatmentStation(double id, char type);
	Node closestContainer(double id, char type, vector<Container> *aux);
	vector<Node> getBestPath(char type, double idBegin);
	void drawPath(vector<Node> path);
};

#endif /* SRC_MAP_CREATOR_H_ */

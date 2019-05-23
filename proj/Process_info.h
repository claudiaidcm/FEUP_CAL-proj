#ifndef SRC_PROCESS_INFO_H_
#define SRC_PROCESS_INFO_H_

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <random>
#include <iostream>

#include "Graph.h"
#include "Node.h"
#include "Road.h"
#include "Garbage_truck.h"
#include "Treatment_station.h"
#include "Container.h"

using namespace std;

class Info {
public:
	/**
	* Original graph
	*/
	Graph<Node> * graphOriginal;
	/**
	* Graph after preprocessing
	*/
	Graph<Node> * graph;
	/**
	* Roads contained in the graph
	*/
	vector<Road *> roads;
	/**
	* Boolean Matrix of N by N indicating if there is a container at a given street intersection, N streets
	*/
	vector<vector<bool>> roadsIntersection;
	/**
	* Trucks contained in the graph
	*/
	vector<Truck *> trucks;
	/**
	* Stations contained in the graph
	*/
	vector<TreatmentStation *> stations;
	/**
	* Containers present in the graph
	*/
	vector<Container *> containers;
	/**
	* Empty constructor
	*/
	Info();
	/**
	* Constructor that imports the graph from the files
	* @param file with node information
	* @param file with road information
	* @param file with node connection information
	*/
	Info(string f1, string f2, string f3);

	void displayRoads();

	void randomizeRoads(int nIntersections);
	/**
	* Preprocesses the original graph
	* @return referance to the graph after preprocessing
	*/
	void preProcessGraph();
	/**
	* Add truck to trucks vector
	* @param t the truck pointer to add
	* @return true if the truck was inserted, false if it was already in the vector
	*/
	bool addTruck(Truck * t);
	/**
	* Add Station to stations vector
	* @param s the station pointer to add
	* @return true if the station was inserted, false if it was already in the vector
	*/
	bool addStation(TreatmentStation * s);
	/**
	* Add Container to containers vector
	* @param c the container pointer to add
	* @return true if the container was inserted, false if it was already in the vector
	*/
	bool addContainer(Container * c);
	/**
	* getter of containers ids
	* @return vector with containers ids
	*/
	vector<string> getContainerIds();
	/**
	* Given a truck in the vector and one container in the vector, get the best path (with the hidden nodes)
	* @param t the truck pointer
	* @param c the container pointer
	* @return vector of nodes, representing the best path
	*/
	vector<Vertex<Node> * > generateSingleTruckSingleContainer(Truck * t, Container * c);
	/**
	* Given a truck in the vector and one station in the vector, get the best path (with the hidden nodes)
	* @param t the truck pointer
	* @param s the station pointer
	* @return vector of nodes, representing the best path
	*/
	vector<Vertex<Node> * > generateOneTruckMultipleContainers(Truck * t, TreatmentStation * s);
	/**
	* Given a station in the vector a volume, get the best path (with the hidden nodes)
	* @param s the station pointer
	* @param trucksVolume inicial volume of the truck
	* @return vector of nodes, representing the best path
	*/
	vector<vector<Vertex<Node> * >> generateMultipleTrucskMultipleContainers(TreatmentStation * s, double trucksVolume);
	/**
	* Floyd-Warshall algorithm to find the shortest path.
	*/
	void floydWarshallShortestPath();
	/**
	* back pre-process the graph
	* @param the path shortened to be back pre-processed
	* @return the resulting path
	*/
	vector<Vertex<Node> *> backPreProcess(vector<Vertex<Node>* > shortenedPath);
	/**
	* recalculates the distances between containers
	* @param int cunrrent position
	* @param true if the containers need to be sorted by distance, false otherwise
	*/
	void recalculateDistContainers(int currentVertexPos, bool isSort);
};

#endif /* SRC_PROCESS_INFO_H_ */

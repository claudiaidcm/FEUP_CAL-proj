#ifndef MAP_CREATOR_H_
#define MAP_CREATOR_H_

#include <vector>
#include <string>
#include <algorithm>

#include "graph.h"
#include "node.h"
#include "road.h"
#include "garbage_truck.h"
#include "treatment_station.h"
#include "container.h"
#include "file_reader.h"
//#include "utils.h"

using namespace std;

class MapCreator {
public:
	Graph<Node> * graphInit; //initial graph
	Graph<Node> * graph; //graph obtained after being processed
	vector<Road *> roads;
	vector<vector<bool>> intersection; //indicates if there is a container at some street intersection
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
	CompleteGraph();
	/**
	* Constructor that imports the graph from the files
	* @param file with node information
	* @param file with road information
	* @param file with node connection information
	*/
	CompleteGraph(string f1, string f2, string f3);

	CompleteGraph & displayRoads();

	CompleteGraph & randomizeRoads(int nIntersections);
	/**
	* Preprocesses the original graph
	* @return referance to the graph after preprocessing
	*/
	CompleteGraph & preProcessGraph();
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
	bool addStation(Station * s);
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
	vector<Vertex<Node> * > generateOneTruckMultipleContainers(Truck * t, Station * s);
	/**
	* Given a station in the vector a volume, get the best path (with the hidden nodes)
	* @param s the station pointer
	* @param trucksVolume inicial volume of the truck
	* @return vector of nodes, representing the best path
	*/
	vector<vector<Vertex<Node> * >> generateMultipleTrucskMultipleContainers(Station * s, double trucksVolume);
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



#endif /* MAP_CREATOR_H_ */

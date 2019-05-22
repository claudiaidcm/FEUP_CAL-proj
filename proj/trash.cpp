#include <iostream>
#include <random>
#include <time.h>
#include <list>
#include <chrono>
#include <iomanip>

#include "File_reader.h"
#include "Graph.h"
#include "Node.h"
#include "Road.h"

using namespace std;

chrono::time_point<chrono::system_clock> time_start;
chrono::duration<double> time_finish;

void timeStart()
{
	time_start = chrono::system_clock::now();
}

void timeFinish(size_t countNodes, string name)
{
	time_finish = chrono::system_clock::now() - time_start;
	cout << "TIME: " << countNodes << " " << time_finish.count() << "(" << name << ")" << endl;
}

/**
* Best path from the garage to the station, by one container
*/
/*vector<Node> singleTruckSingleContainer(CompleteGraph * cgraph, Truck * t, Container * c, Station * s) {
	vector<Node> res;
	vector<Vertex<Node> *> temp = cgraph->graph->getVertexSet();
	if (temp.size() <= 3) {
		cout << "Not enough nodes to run singleTruckSingleContainer" << endl;
		return res;//makes no sense to run the algorithm
	}
	//save the truck and container and station
	cgraph->trucks.clear();
	cgraph->addTruck(t);
	cgraph->containers.clear();
	cgraph->addContainer(c);
	cgraph->stations.clear();
	cgraph->addStation(s);
	//output the data
	cout << "Garage: " << t->getGarage().getId()
		<< ", Container: " << c->getId()
		<< ", Station: " << s->getId() << endl;
	//empty the vector and add the new satation

	//get the best path for this case
	vector<Vertex<Node> *> fullRes = cgraph->generateSingleTruckSingleContainer(t, c);
	fullRes = cgraph->backPreProcess(fullRes);
	res = Graph<Node>::getInfoFromVector(fullRes);
	for (auto node : res)
		cout << "->" << node.getId();
	cout << endl;
	cout << "TOTAL DISTANCE: " << getTotalDistance(res) << endl;
	return res;
}*/

int main1() {
	srand(time(NULL));

	return 0;
}

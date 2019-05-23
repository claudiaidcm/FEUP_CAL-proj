#include "File_reader.h"

Node getNodeFromMap1(string line) { //Node_id; latDeg; lonDeg; latRad; lonRad
	smatch matches;
	regex r("(\\d+);(.+);(.+);(.+);(.+)");

	if (regex_search(line, matches, r) && matches.size() == 6)
		return Node(matches[1], stod(matches[5]), stod(matches[4]));
	cout << "Failed to read NODE, wrong format(" << line << ")" << endl;

	exit(1);
}

Road * getRoadFromMap2(string line) {//Road_id; StreetName; IsBothWays
	smatch matches;
	regex r("(\\d*);(.*);(False|True)");

	if (regex_search(line, matches, r) && matches.size() == 4)
		return new Road(matches[1], matches[2], matches[3] == "True");
	cout << "Failed to read ROAD, wrong format(" << line << ")" << endl;

	return nullptr;
}

bool fileExists(string filename) {
	ifstream f;
	f.open(filename);
	if (f.is_open()) {
		f.close();
		return true;
	} else {
		return false;
	}
}

void getInfoFromMap3(string line, string & roadID, string & node1ID, string & node2ID) { //Road_id; Node1_id; Node2_id
	smatch matches;
	regex r("(\\d*);(\\d*);(\\d*)");

	if (regex_search(line, matches, r) && matches.size() == 4) {
		roadID = matches[1];
		node1ID = matches[2];
		node2ID = matches[3];
		return;
	}
	cout << "Failed to read EDGE, wrong format(" << line << ")" << endl;
}

vector<string> readFile(string filename) {
	cout << "Reading file ("<< filename << ")...";
	ifstream f;
	string line;
	vector <string> result;

	f.open(filename);

	if (f.is_open()) {
		while (getline(f, line)) {
			if (line != "") {//in case there are any additional empty lines in the file
				result.push_back(line);
			}
		}
		f.close();
	}
	cout << "Done" << endl;
	return result;
}

Graph<Node>* getGraphFromFiles(string m1, string m2, string m3, vector<Road *> & roads) {
	vector<string> v1, v2, v3;
	roads.clear();//to hold the roads information

	Graph<Node> * graph =  new Graph<Node>;//the graph read from the files

	//check no mistakes
	if (!fileExists(m1) || !fileExists(m2) || !fileExists(m3)) {
		cout << "ERROR READING FILES ("<< m1 <<","<< m2<<"," << m3<< ")" << endl;
		exit(1);
	}

	//read files into vectors
	v1 = readFile(m1);
	v2 = readFile(m2);
	v3 = readFile(m3);

	cout << "Reading Nodes into the Graph...";
	for (auto line: v1)
		graph->addVertex(getNodeFromMap1(line));
	cout << "Done(" << graph->getNumVertex() << " Nodes)" << endl;

	//read all the rows into a vector of Road (passed by reference), to relate them to the nodes in the next section
	cout << "Reading Roads into vector...";
	for (auto line : v2)
		roads.push_back(getRoadFromMap2(line));
	cout << "Done(" << roads.size() <<" roads)" << endl;

	//(string f1line, string & roadId, string & node1Id, string & node2Id)
	string rID, n1ID, n2ID; //variables to hold the:roadId, node1Id, node2Id
	Road * road;//the current row to be treated as a graph edge
	Node tempO = Node();
	Node tempD = Node();
	int countFailedRoads = 0, countEdges = 0;
	cout << "Creating the edges with the roads..." << endl;
	for (auto line : v3) {
		countEdges++;
		getInfoFromMap3(line, rID, n1ID, n2ID);//read one connection type
		if ((road = Road::findRoadByID(roads, rID)) == nullptr) {
			cout << "	Road with ID " << rID << " not found" << endl;
			countFailedRoads++;
			continue;
		}
		tempO = Node(n1ID);//the nodes are initialized with the correct id so that the search works,
		tempD = Node(n2ID);//because operator== is defined for the Node class
		if (!graph->addEdgePair(graph->getTwoVertexs(tempO, tempD), 0, road->bothWays))//adds the edge to the graph
			cout << "failed to add edge from " << n1ID << " to " << n2ID << endl;
	}
	cout << "...Done(failed " << countFailedRoads << "/"<< countEdges <<")" << endl;

	return graph;
}





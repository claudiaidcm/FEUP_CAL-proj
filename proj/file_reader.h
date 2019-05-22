#ifndef FILE_READER_H_
#define FILE_READER_H_

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <regex>

#include "Graph.h"
#include "Node.h"
#include "Road.h"

using namespace std;

vector<string> readFile(string filename);

bool fileExists(string filename);

Node getNodeFromMap1(string line);

Road* getRoadFromMap2(string line);

void getInfoFromFile3(string line, string & roadId, string & node1Id, string & node2Id);

Graph<Node> * getGraphFromFiles(string m1, string m2, string m3, string m4);


#endif /* FILE_READER_H_ */

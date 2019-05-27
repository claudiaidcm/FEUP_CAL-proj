#include <cstdio>
#include <fstream>
#include <iostream>
#include <sstream>

#include "graphviewer.h"
#include "map_creator.h"

int main() {
	map_creator init;

	init.getNodes("T02_nodes_X_Y_Aveiro.txt");
	init.getEdges("T02_edges_Aveiro.txt");
	init.getTags("T02_tags_Aveiro.txt");

	init.showGraph();

	return 0;
}

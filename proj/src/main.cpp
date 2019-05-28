#include <cstdio>
#include <fstream>
#include <iostream>
#include <sstream>

#include "graphviewer.h"
#include "map_creator.h"

void getPath(map_creator &init) {
	double id;
	cout << "Choose a waste transfer station to start (insert the node id): \n";
	cin >> id;

	if (!(init.isTransferStation(id))) {
		cout << "Not a valid waste transfer station.";
		return;
	}

	cout
			<< "Which type of garbage do you want to collect? 1 - recycling residues. 2 - regular residues. \n";
	int t;
	cin >> t;

	char type;
	if (t == 1)
		type = 'r';
	else
		type = 'n';

	cout << "How many trucks do you have?";
	int n;
	cin >> n;
	cout << "Which is its maximum capacity?";
	double capacity;
	cin >> capacity;

	for (int i = 1; i <= n; i++) {
		Truck t = Truck(id, capacity, type);
		init.addTruck(t);
	}

	cout << "Getting Path!\n";
	vector<Node> res = init.getBestPath(type, id);

	init.showGraph();
}

void connectivity(map_creator &init) {
	cout << "The graph ";
	if (!init.getGraph().hasConnection())
		cout << "is not all connected." << endl;
	else
		cout << "is all connected." << endl;
}

int menu(map_creator &init) {
	int option;

	cout << "Choose an option:\n";
	cout << "1 - Show map.\n";
	cout << "2 - Get best path.\n";
	cout << "3 - Check connectivity. \n";
	cout << "4 - Exit\n";

	cin >> option;

	if (option == 1) {
		init.showGraph();
		getchar();
		return 1;
	} else if (option == 2) {
		getPath(init);
		return 1;
	} else if (option == 3) {
		connectivity(init);
		return 1;
	} else if (option == 4) {
		cout << "EXIT.\n";
		return 0;
	}

	else {
		cout << "Not a valid option. Try Again!";
		return 1;
	}
}

int main() {
	cout << "ECOPONTO\n" << endl;
	cout << "Extracting info from files...\n";

	map_creator init;
	init.getNodes("T02_nodes_X_Y_Aveiro.txt");
	init.getEdges("T02_edges_Aveiro.txt");
	init.getTags("T02_tags_Aveiro.txt");

	int terminate = menu(init);
	while (terminate != 0) {
		terminate = menu(init);
	}

	return 0;
}

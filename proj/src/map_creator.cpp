#include "map_creator.h"

using namespace std;

map_creator::map_creator() {
	gv = new GraphViewer(800, 800, false);
}

void map_creator::getNodes(string nodes_file) {
	string line;
	ifstream file(nodes_file);

	if (file.is_open()) {
		getline(file, line);
		stringstream linestream(line);
		int nodes_number;
		double idNode;
		double x;
		double y;

		linestream >> nodes_number;

		while (getline(file, line)) {
			stringstream linestream(line);
			getline(linestream, line, '(');
			linestream >> idNode;
			getline(linestream, line, ',');
			linestream >> x;
			getline(linestream, line, ' ');
			linestream >> y;

			Node node = Node(idNode, x, y);
			nodes.push_back(node);
			graph.addVertex(node);
		}

		file.close();
	} else {
		cerr << "Nodes file not found!\n";
	}

	return;
}

void map_creator::getEdges(string edges_file) {
	string line;
	ifstream file(edges_file);

	if (file.is_open()) {
		getline(file, line);
		stringstream linestream(line);
		int edges_number;

		linestream >> edges_number;

		while (getline(file, line)) {

			double idBegin;
			double idEnd;

			stringstream linestream(line);
			getline(linestream, line, '(');
			linestream >> idBegin;
			getline(linestream, line, ',');
			linestream >> idEnd;

			Node n;
			Node nodeOrigin;
			Node nodeDestiny;

			for (unsigned int i = 0; i < graph.getVertexSet().size(); i++) {

				if (idBegin == graph.getVertexSet().at(i)->getInfo().getId())
					nodeOrigin = graph.getVertexSet().at(i)->getInfo();

				if (idEnd == graph.getVertexSet().at(i)->getInfo().getId()) {
					nodeDestiny = graph.getVertexSet().at(i)->getInfo();
				}
			}

			double weight;
			weight = sqrt(
					pow(nodeDestiny.getX() - nodeOrigin.getX(), 2)
							+ pow(nodeDestiny.getY() - nodeOrigin.getY(), 2));
			graph.addEdge(nodeOrigin, nodeDestiny, weight);
		}

		file.close();
	} else {
		cerr << "Edges file not found!\n";
	}

	return;
}

void map_creator::getTags(string tags_file) {
	string line;
	ifstream file(tags_file);

	if (file.is_open()) {
		getline(file, line);
		stringstream linestream(line);
		int tags_number;

		linestream >> tags_number;

		while (tags_number > 0) {

			getline(file, line);
			getline(file, line);
			stringstream linestream(line);
			int n;

			linestream >> n;

			//waste baskets
			while (n > 0) {
				getline(file, line);
				stringstream linestream(line);
				double id_node;
				linestream >> id_node;

				Vertex<Node> *vert = NULL;

				double aux = 0;
				for (unsigned int j = 0; j < graph.getVertexSet().size(); j++) {
					aux = graph.getVertexSet().at(j)->getInfo().getId();
					if (id_node == aux) {
						vert = graph.getVertexSet().at(j);
						break;
					}

				}

				Container cont = Container(vert, true, 10, 'n');
				containers.push_back(cont);
				n--;
			}

			tags_number--;

			getline(file, line);
			getline(file, line);
			stringstream linestream1(line);

			linestream1 >> n;

			//amenity=recycling
			while (n > 0) {
				getline(file, line);
				n--;
			}

			tags_number--;

			getline(file, line);
			getline(file, line);
			stringstream linestream2(line);

			linestream2 >> n;

			//waste disposals
			while (n > 0) {
				getline(file, line);
				stringstream linestream(line);
				double id_node;
				linestream >> id_node;

				Vertex<Node> *vert = NULL;

				double aux = 0;
				for (unsigned int j = 0; j < graph.getVertexSet().size(); j++) {
					aux = graph.getVertexSet().at(j)->getInfo().getId();
					if (id_node == aux) {
						vert = graph.getVertexSet().at(j);
						break;
					}

				}

				Container cont = Container(vert, true, 100, 'n');
				containers.push_back(cont);
				n--;
			}

			tags_number--;

			getline(file, line);
			getline(file, line);
			stringstream linestream3(line);

			linestream3 >> n;

			//bin = *
			while (n > 0) {
				getline(file, line);
				n--;
			}

			tags_number--;

			getline(file, line);
			getline(file, line);
			stringstream linestream4(line);

			linestream4 >> n;

			//landuse = landfill
			while (n > 0) {
				getline(file, line);
				stringstream linestream(line);
				double id_node;

				linestream >> id_node;

				Vertex<Node> *vert = NULL;

				double aux = 0;
				for (unsigned int j = 0; j < graph.getVertexSet().size(); j++) {
					aux = graph.getVertexSet().at(j)->getInfo().getId();
					if (id_node == aux) {
						vert = graph.getVertexSet().at(j);
						break;
					}

				}

				TreatmentStation station = TreatmentStation(vert, 'n');
				treatment_stations.push_back(station);
				n--;
			}

			tags_number--;

			getline(file, line);
			getline(file, line);
			stringstream linestream5(line);

			linestream5 >> n;

			//recycling containers
			while (n > 0) {
				getline(file, line);
				stringstream linestream(line);
				double id_node;

				linestream >> id_node;

				Vertex<Node> *vert = NULL;

				double aux = 0;
				for (unsigned int j = 0; j < graph.getVertexSet().size(); j++) {
					aux = graph.getVertexSet().at(j)->getInfo().getId();
					if (id_node == aux) {
						vert = graph.getVertexSet().at(j);
						break;
					}

				}

				Container cont = Container(vert, true, 100, 'r');
				containers.push_back(cont);
				n--;
			}

			tags_number--;

			getline(file, line);
			getline(file, line);
			stringstream linestream6(line);

			linestream6 >> n;

			//recycling stations
			while (n > 0) {
				getline(file, line);
				stringstream linestream(line);
				double id_node;

				linestream >> id_node;

				Vertex<Node> *vert = NULL;

				for (unsigned int i = 0; i < graph.getVertexSet().size(); i++) {
					if (id_node
							== graph.getVertexSet().at(i)->getInfo().getId()) {
						vert = graph.getVertexSet().at(i);
						break;
					}
				}

				TreatmentStation station = TreatmentStation(vert, 'r');
				treatment_stations.push_back(station);
				n--;
			}

			tags_number--;

			getline(file, line);
			getline(file, line);
			stringstream linestream7(line);

			linestream7 >> n;

			//waste transfer station
			while (n > 0) {
				getline(file, line);
				stringstream linestream(line);
				double id_node;

				linestream >> id_node;

				Vertex<Node> *vert = NULL;

				for (unsigned int i = 0; i < graph.getVertexSet().size(); i++) {
					if (id_node
							== graph.getVertexSet().at(i)->getInfo().getId()) {
						vert = graph.getVertexSet().at(i);
						break;
					}
				}

				transfer_stations.push_back(vert);
				n--;
			}

			tags_number--;

			getline(file, line);
			getline(file, line);
			stringstream linestream8(line);

			linestream8 >> n;

			//waste = *
			while (n > 0) {
				getline(file, line);
				n--;
			}

			tags_number--;
		}

		file.close();
	} else {
		cerr << "Edges file not found!\n";
	}

	return;
}

void map_creator::showGraph() {

	gv->createWindow(800, 800);

	vector<Vertex<Node> *> info = graph.getVertexSet();
	Node origin = info[0]->getInfo();

	for (unsigned int i = 0; i < info.size(); i++) {
		Node point = info[i]->getInfo();

		int idNo = point.getId();
		int x = point.getX();
		int y = point.getY();

		gv->addNode(idNo, x - origin.getX(), y - origin.getY());

		if (isContainer(idNo)) {
			gv->setVertexColor(idNo, "BLUE");
		}

		if (isLandFill(idNo)) {
			gv->setVertexColor(idNo, "RED");
		}

		if (isRecyclingContainer(idNo)) {
			gv->setVertexColor(idNo, "GREEN");
		}

		if (isRecyclingStation(idNo)) {
			gv->setVertexColor(idNo, "MAGENTA");
		}

		if (isTransferStation(idNo)) {
			gv->setVertexColor(idNo, "CYAN");
		}

	}

	for (unsigned int i = 0; i < info.size(); i++) {
		Node begin = info[i]->getInfo();
		int idNo_begin = begin.getId();

		vector<Edge<Node>> adj = info[i]->getAdj();

		for (unsigned int j = 0; j < adj.size(); j++) {

			int idNo_end = adj.at(j).getNode()->getInfo().getId();

			gv->addEdge(100 * idNo_begin + idNo_end, idNo_begin, idNo_end,
					EdgeType::DIRECTED);
		}
	}

	gv->rearrange();
}

void map_creator::drawPath(vector<Node> path) {
	for (size_t i = 0; i < path.size() - 1; i++) {
		int id = 100 * path.at(i).getId() + path.at(i + 1).getId();

		gv->setEdgeThickness(id, 4);
		gv->setEdgeColor(id, "YELLOW");
	}

	gv->setVertexColor(path.at(0).getId(), "BLACK");
	gv->rearrange();
}

Node map_creator::getNodeByID(int id) {

	Node node;

	for (unsigned int i = 0; i < graph.getVertexSet().size(); i++) {
		if (graph.getVertexSet().at(i)->getInfo().getId() == id) {
			node = graph.getVertexSet().at(i)->getInfo();
		}
	}

	return node;

}

bool map_creator::isContainer(int idNo) {
	for (unsigned int i = 0; i < containers.size(); i++) {
		if (containers.at(i).getNode()->getInfo().getId() == idNo)
			if (containers.at(i).getType() == 'n')
				return true;
	}

	return false;
}

bool map_creator::isLandFill(int idNo) {
	for (unsigned int i = 0; i < treatment_stations.size(); i++) {
		if (treatment_stations.at(i).getNode()->getInfo().getId() == idNo)
			if (treatment_stations.at(i).getType() == 'n')
				return true;
	}

	return false;
}

bool map_creator::isRecyclingContainer(int idNo) {
	for (unsigned int i = 0; i < containers.size(); i++) {
		if (containers.at(i).getNode()->getInfo().getId() == idNo)
			if (containers.at(i).getType() == 'r')
				return true;
	}

	return false;
}

bool map_creator::isRecyclingStation(int idNo) {
	for (unsigned int i = 0; i < treatment_stations.size(); i++) {
		if (treatment_stations.at(i).getNode()->getInfo().getId() == idNo)
			if (treatment_stations.at(i).getType() == 'r')
				return true;
	}

	return false;
}

bool map_creator::isTransferStation(int idNo) {
	for (unsigned int i = 0; i < transfer_stations.size(); i++) {
		if (transfer_stations.at(i)->getInfo().getId() == idNo)
			return true;
	}

	return false;
}

Node map_creator::closestTreatmentStation(double id, char type) {
	Node node = getNodeByID(id);
	int distMinima = INF;
	int pos = -1;

	for (unsigned int i = 0; i < treatment_stations.size(); i++) {
		if (treatment_stations.at(i).getType() == type) {
			graph.dijkstraShortestPath(
					treatment_stations.at(i).getNode()->getInfo()); //faz dijkstra para a bomba analisada

			int distAtual = graph.getVertex(node)->getDist(); //distancia da bomba analisada ate ao node

			if (distAtual <= distMinima) { //se distancia atual menor que a distancia guardada
				pos = i; //atualiza posicao
				distMinima = distAtual; //atualiza distancia guardada
			}
		}
	}

	return containers.at(pos).getNode()->getInfo();
}

Node map_creator::closestContainer(double id, char type,
		vector<Container> *aux) {
	Node node = getNodeByID(id);
	int distMinima = INF;
	int pos = -1;
	Node res;

	for (unsigned int i = 0; i < aux->size(); i++) {
		if ((aux->at(i).getType() == type) && (aux->at(i).isFull() == true)
				&& (aux->at(i).getNode()->getInfo().getId() != id)) {
			graph.dijkstraShortestPath(aux->at(i).getNode()->getInfo()); //faz dijkstra para a bomba analisada

			int distAtual = graph.getVertex(node)->getDist(); //distancia da bomba analisada ate ao node

			if (distAtual <= distMinima) { //se distancia atual menor que a distancia guardada
				pos = i; //atualiza posicao
				distMinima = distAtual; //atualiza distancia guardada
			}
		}
	}

	res = aux->at(pos).getNode()->getInfo();
	aux->erase(aux->begin() + pos);

	return res;
}

Container map_creator::searchContainer(double id) {
	for (unsigned int i = 0; i < containers.size(); i++) {
		if (containers.at(i).getNode()->getInfo().getId() == id)
			return containers.at(i);
	}
}

vector<Node> map_creator::getBestPath(char type, double idBegin) {

	cout << "Started searching...\n";

	Node node;
	double src = 0;
	vector<Node> passed;
	vector<Container> aux = containers;

	passed.push_back(getNodeByID(idBegin));

	high_resolution_clock::time_point t1 = high_resolution_clock::now();

	for (size_t i = 0; i < trucks.size(); i++) {
		Truck first = trucks[0];
		if (aux.size() != 0) {
			node = closestContainer(idBegin, type, &aux);
			Container cont = searchContainer(node.getId());

			while (first.getFreeVolume() > 0
					&& first.getFreeVolume() >= cont.getCapacity()
					&& cont.isFull()) {
				src = node.getId();
				cont.setFull(false);
				first.setFreeVolume(first.getFreeVolume() - cont.getCapacity());
				passed.push_back(node);
				cout << "Visiting container in node: " << node.getId() << endl;
				node = closestContainer(src, type, &aux);
				cont = searchContainer(node.getId());
			}

			node = closestTreatmentStation(src, type);
			cout << "Ending in closest treatment station in node: "
					<< node.getId() << endl;
			passed.push_back(node);

			for (size_t i = 0; i < passed.size(); i++) {
				cout << passed.at(i).getId() << ">>";
			}

			drawPath(passed);

			cout << endl << endl;

			passed.erase(passed.begin() + 1,
					passed.begin() + passed.size() - 1);
		}

		high_resolution_clock::time_point t2 = high_resolution_clock::now();
		auto duration = duration_cast < microseconds > (t2 - t1).count();
	}

	return passed;
}

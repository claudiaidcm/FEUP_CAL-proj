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

				Container cont = Container(vert, false, 10, 'n');
				containers.push_back(cont);
				n--;
			}

			tags_number--;

			getline(file, line);
			getline(file, line);
			linestream >> n;

			//amenity=recycling
			while (n > 0) {
				getline(file, line);
				n--;
			}

			tags_number--;

			getline(file, line);
			getline(file, line);
			linestream >> n;

			//waste baskets
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

				Container cont = Container(vert, false, 100, 'n');
				containers.push_back(cont);
				n--;
			}

			tags_number--;

			getline(file, line);
			getline(file, line);
			linestream >> n;

			//bin = *
			while (n > 0) {
				getline(file, line);
				n--;
			}

			tags_number--;

			//landuse = landfill
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

				TreatmentStation station = TreatmentStation(vert, 'n');
				stations.push_back(station);
				n--;
			}

			tags_number--;

			getline(file, line);
			getline(file, line);
			linestream >> n;

			//recycling containers
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

				Container cont = Container(vert, false, 100, 'r');
				containers.push_back(cont);
				n--;
			}

			tags_number--;

			getline(file, line);
			getline(file, line);
			linestream >> n;

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
				stations.push_back(station);
				n--;
			}

			tags_number--;

			getline(file, line);
			getline(file, line);
			linestream >> n;

			//waste transfer station
			while (n > 0) {
				getline(file, line);
				n--;
			}

			tags_number--;

			getline(file, line);
			getline(file, line);
			linestream >> n;

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

		if (isWasteBascket(idNo)) {
			gv->setVertexColor(idNo, "BLUE");
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

	getchar();
}

bool map_creator::isWasteBascket(int idNo) {
	for (unsigned int i = 0; i < containers.size(); i++) {
		if (containers.at(i).getId() == idNo)
			if (containers.at(i).getCapacity() == 10)
				if (containers.at(i).getType() == 'n') {
					return true;
				}

	}

	return false;
}

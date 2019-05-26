#ifndef ROAD_H_
#define ROAD_H_

#include <string>
#include <vector>
#include <ostream>

using namespace std;

class Road {
public:
	string ID;
	string name;
	bool bothWays; //if the road goes bothways or not

	Road();
	Road(string ID, string name, bool bothWays);
	friend ostream& operator<<(ostream& os, const Road& r);
	static Road * findRoadByID(vector<Road *> roads, string ID);
};




#endif /* ROAD_H_ */

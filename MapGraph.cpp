#include "MapGraph.h"

MapGraph::Node::Node(string k, HashMap * m){
    key = k;
    map = m;
}

void MapGraph::addEdge(Node * n1, Node * n2){
	// cout<<"adding edge between "<<n1->key<<" and "<<n2->key<<endl;
    n1->adj.push_back(n2);
    n2->adj.push_back(n1);
}

MapGraph::Node * MapGraph::getNode(string key, string mapID){
    for (int i = 0; i < nodes.size(); ++i){
        if (nodes.at(i)->key == key && nodes.at(i)->map->mapID == mapID)
            return nodes.at(i);
    }
    return NULL;
}

MapGraph::Node * MapGraph::getFirstNode(string key){
    for (int i = 0; i < nodes.size(); ++i){
        if (nodes.at(i)->key == key)
            return nodes.at(i);
    }
    return NULL;
}

void MapGraph::addNode(string key, HashMap * map){
	Node * n = new Node(key, map);
	for (int i = 0; i < nodes.size(); ++i){
		if (nodes.at(i)->key == key){
			addEdge(n, nodes.at(i));
		}
	}
    nodes.push_back(n);
}

string MapGraph::getToken(string input, string delim, int n) {
	int a = 0;
	int b = input.find_first_of(delim, a);
	for (int i = 0; i < n; ++i) {
		a = b + 1;
		b = input.find_first_of(delim, a);
	}
	return input.substr(a, (b - a));
}

void MapGraph::addMap(string file) {
	// cout<<"Reading file: "<<file<<endl;
	ifstream mapfile(file);

	// map ID is filename
	string mid = getToken(file, ".", 0);

	cout<<"Generated Map: "<<mid<<endl;
	

	HashMap * map = new HashMap(1000, mid);	
	

	string line;
	if (mapfile) {
		while (getline(mapfile, line)) {
			string key = getToken(line, "\%", 0);
			string val = getToken(line, "\%", 1);

			//cout<<"'"<<key<<"' '"<<val<<"'"<<endl;

			map->insert(key, val);
			
			addNode(key, map);
		}
		mapfile.close();
	}

	maps.push_back(map);
}

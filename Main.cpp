#include <iostream>
#include <string>
#include <fstream>
#include <locale>
#include <cstdlib> 
#include <set>
#include <vector>
#include <ctime>
#include <sstream>
#include "MapGraph.h"

using namespace std;

int menu(MapGraph * graph){
    int choice;
	string mid, key;
    while (1) {
		cout<<"===========Menu============"<<endl;
		cout<<"1. View entry relation data"<<endl;
		cout<<"2. View entry in map"<<endl;
		cout<<"3. View random node"<<endl;
		cout<<"============================"<<endl;		
        string ln;
		getline(cin,ln);
		stringstream numberln(ln);
		numberln >> choice;
        switch(choice) {
	        case 1:
	        	try { 
					cout<<"Key: "<<endl;
					getline(cin, key);
					MapGraph::Node * n = graph->getFirstNode(key);
					if (n== NULL) cout<<"Unable to find node"<<endl;
					else{
						cout<<n->map->mapID<<" : "<<n->map->find(n->key)<<endl;
						for (int i = 0; i < n->adj.size(); ++i){
							cout<<n->adj.at(i)->map->mapID<<" : ";
							cout<<n->adj.at(i)->map->find(n->adj.at(i)->key);
							cout<<endl;
						}
					}
				} catch (int e){
					cout<<"Invalid."<<endl;
				}
	            break;
	        case 2:
		        try { 
					cout<<endl<<"MapID: "<<endl;
					getline(cin, mid);
					cout<<"Key: "<<endl;
					getline(cin, key);
					MapGraph::Node * n = graph->getNode(key, mid);
					if (n== NULL) cout<<"Unable to find node"<<endl;
					else {					
						cout<<"Found node "<<n->key<<" in "<<n->map->mapID<<endl;
						cout<<"Value: "<<n->map->find(n->key)<<endl;
						cout<<"Related Nodes: "<<n->adj.size()<<endl;
					}
				} catch (int e){
					cout<<"Invalid."<<endl;
				}
	            break;
			case 3:
				try { 
					int i = (rand()%graph->nodes.size());

					MapGraph::Node * n = graph->nodes.at(i);
					cout<<"Key : \""<<n->key<<"\""<<endl;
					cout<<n->map->mapID<<" : "<<n->map->find(n->key)<<endl;
					for (int i = 0; i < n->adj.size(); ++i){
						cout<<n->adj.at(i)->map->mapID<<" : ";
						cout<<n->adj.at(i)->map->find(n->adj.at(i)->key);
						cout<<endl;
					}

				} catch (int e){
					cout<<"Invalid."<<endl;
				}
	            break;
	        default:
	           cout<<"\nEnter correct option\n";
       }
    }
    return 0;
}



int main(int argc, char ** argv){
	if (argc < 2){
		cout<<"usage: "<<argv[0]<<" <input files>"<<endl;
		return -1;
	}

	MapGraph * graph = new MapGraph();

	for (int i = 1; i < argc; ++i)
		graph->addMap(argv[i]);

	menu(graph);
}

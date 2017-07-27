#pragma once
#include <vector>
#include <string>
#include <fstream>
#include "HashMap.h"
using namespace std;

class MapGraph {
    public:
        // Node consists of reference to a hashmap and key for a value in the map
        // also holds a list of adjacent nodes
        class Node{
            public:
                string key;
                HashMap * map;
                vector<Node*> adj;
                Node(string k, HashMap * m);
        };

        // creates an Edge between nodes n1 and n2
        void addEdge(Node * n1, Node * n2);
        
        // returns first node with the given key and mapID
        Node * getNode(string key, string mapID);

        // returns first node with the given key
        Node * getFirstNode(string key);

        void addNode(string key, HashMap * map);

        void addMap(string file);

        vector<Node*> nodes;

        vector<HashMap*> maps;

    private:

        string getToken(string input, string delim, int n);

};
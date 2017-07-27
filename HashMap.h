#pragma once
#include <iostream>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <ctime>

using namespace std;
 
class AssocData {

    public:
        string key;
        string value;
        AssocData *next;
        AssocData(string key, string value) {
            this->key = key;
            this->value = value;
            this->next = NULL;
        }
};

class HashMap {
    
    private:
        int tsize;
        AssocData **table;

    public:           

        string mapID;

        // using linear probing n=1
        int probe_amt = 1;

        HashMap(int size, string ID);

        int exp(int n, int k);

        int hashCode(string key);

        void insert(string key, string value);

        string find(string key);

        void remove(string key);
};

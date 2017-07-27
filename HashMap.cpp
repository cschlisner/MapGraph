#include "HashMap.h"


HashMap::HashMap(int size, string ID) {
    mapID = ID;
    tsize = size;
    table = new AssocData*[tsize];
    for (int i = 0; i < tsize; i++) {
        table[i] = NULL;
    }
}

int HashMap::exp(int n, int k){
    int ex = 1;
    for (int i = 0; i < k; ++i)
        ex *= n;
    return ex;
}

int HashMap::hashCode(string key) {
    long hc = 0;
    for (int i = 0 ; i < key.length(); ++i){
        hc += key[i] * exp(32, key.length()-(i+1));
    }

    int i = hc % tsize;
    return i >= 0 ? i : -i;         
}

void HashMap::insert(string key, string value) {

    int hash = hashCode(key);
    while (table[hash] != NULL && table[hash]->key != key) {
        hash += probe_amt;
        if (hash >= tsize)
            hash -= tsize;
    }
    if (table[hash] != NULL){
        delete table[hash];
    }
    //cout<<"Inserting "<<key<<":"<<value<<" into map: "<<mapID<<endl;
    table[hash] = new AssocData(key, value);           
}

string HashMap::find(string key) {
    int  hash = hashCode(key);
    while (table[hash] != NULL && table[hash]->key != key) {
        hash += probe_amt;
        if (hash >= tsize)
            hash -= tsize;
    }
    
    if (table[hash] != NULL){
        return table[hash]->value;
    }
}

void HashMap::remove(string key) {
    int hash = hashCode(key);
    while (table[hash] != NULL) {
        if (table[hash]->key == key)
            break;
        hash += probe_amt;
        if (hash >= tsize)
            hash -= tsize;
    }
    
    if (table[hash] == NULL) {
        cout<<"No Element found at key "<<key<<endl;
        return;
    }
    else delete table[hash];
    cout<<"Element Deleted"<<endl;
}


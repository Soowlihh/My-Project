#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>
#include <vector>
#include <list>
using namespace std;

//Function for HashTable to store passwords
class HashTable{
    public: 
    HashTable();
    bool insert(const string& hash, const string& original);
    bool lookup(const string& hash, string& originalOut);

    private:
    vector<list<pair<string , string > > > table;
    int capacity;
    int count;
    float loadFactorLimit;
    int getIndex(const string& hash) const;
    void resize();
};

#endif

#include "HashTable.h"
#include <functional>
#include <iostream>

using namespace std;

//constructor
HashTable::HashTable(): capacity(10), count(0), loadFactorLimit(0.75f) {table.resize(capacity);}

//HashFunction
int HashTable::getIndex(const string& hash) const {
    std::hash <std::string> hasher;
    return hasher(hash) % capacity;
}
//Inserts a password candidate with its hash
bool HashTable::insert(const string& hash, const string& original){
    if((float)(count + 1) / capacity > loadFactorLimit) {
        resize();
    }
    int index = getIndex(hash);

    for(const auto& entry : table[index]) {
        if(entry.first == hash) {
            return false;
        }
    }
    table[index]. push_back({hash, original});
    count++;
    return true;
}
//Function to lookup passwords
bool HashTable::lookup(const string& hash, string& originalOut) {
    int index = getIndex(hash);
    for (const auto& entry : table[index]) {
        if (entry.first == hash) {
            originalOut = entry.second;
            return true;
        }
    }
    return false;
}

//Resize the table when it's full
void HashTable::resize() {
int oldCapacity = capacity;
capacity *= 2;

vector<list<pair<string,string>>> newTable(capacity);

for(const auto& bucket : table) {
    for(const auto& entry : bucket) {
        int newIndex = hash<string>{}(entry.first) % capacity;
        newTable[newIndex].push_back(entry);
    }
}
table = std::move(newTable);
}

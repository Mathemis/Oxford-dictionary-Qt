#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "linkedlist.h"
#include <fstream>
#include <vector>
#include <cstdio>
//#include <string>
using namespace std;
#define MAX 40000



class HashTable {
private:
    LinkedList<string> BucketArray[MAX];

    uint32_t hashCode(const string &s)
    {
        uint32_t hash = 5831;
        size_t i = 0;
        while (i < s.size())
            hash = ((hash << 5) + hash) + uint32_t(s[i++]);//hash * 33 + s[i++];
        return hash % MAX;
    }

public:

    HashTable()
    {
    }

    string search(const string &k) {
        return BucketArray[hashCode(k)].search(k);
    }


    void insert(const string &k, const string &v) {
        BucketArray[hashCode(k)].insert(k, v);
    }


    bool modify(const string &k, const string &v) {
        return BucketArray[hashCode(k)].modify(k, v);
    }


    void remove(const string &k) {
        BucketArray[hashCode(k)].remove(k);
    }


    void traversal(fstream &file) {
        for (int i = 0; i < MAX; i++)
            BucketArray[i].traversal(file);
    }

    void clear() {
        for (int i = 0; i < MAX; i++)
            BucketArray[i].clear();
    }

    ~HashTable()
    {
        HashTable::clear();
    }
};

#endif // HASHTABLE_H

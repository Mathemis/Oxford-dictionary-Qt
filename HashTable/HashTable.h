#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "LinkedList.h"
#include <fstream>
#include <vector>
#include <cstdio>
#define MAX 40000



class HashTable {
private:
	LinkedList<string> BucketArray[MAX];
	unsigned long hashCode(const string &s);
public:
	HashTable() {}
	~HashTable() { clear(); }

	string search(const string &);
	void insert(const string &, const string &);
	bool modify(const string &, const string &);
	void remove(const string &);
	void traversal(fstream &);
	
	void clear();
};


// DEFINITION

unsigned long HashTable::hashCode(const string &s)
{
	unsigned long hash = 5831;
	int i = 0;
	while (i < s.size())
		hash = ((hash << 5) + hash) + s[i++];//hash * 33 + s[i++];
	return hash % MAX;
}



string HashTable::search(const string &k) {
	return BucketArray[hashCode(k)].search(k);
}


void HashTable::insert(const string &k, const string &v) {
	BucketArray[hashCode(k)].insert(k, v);
}


bool HashTable::modify(const string &k, const string &v) {
	return BucketArray[hashCode(k)].modify(k, v);
}


void HashTable::remove(const string &k) {
	BucketArray[hashCode(k)].remove(k);
}


void HashTable::traversal(fstream &file) {
	for (int i = 0; i < MAX; i++)
		BucketArray[i].traversal(file);
}

void HashTable::clear() {
	for (int i = 0; i < MAX; i++)
		BucketArray[i].clear();
}



#endif /*HASHTABLE_H*/

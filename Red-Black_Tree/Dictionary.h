#ifndef DICTIONARY_H
#define DICTIONARY_H

#define _CRT_SECURE_NO_WARNINGS

#include "RBTree.h"
#include <fstream>
#include <vector>
#include <cstdio>





class DictionaryInterface {
private:
	RBTree<string> data;
	void Tokenizer(const string &, string &, string &);

public:
	DictionaryInterface() {}
	~DictionaryInterface() { data.clear(); }

	void ReadFile(const string &);
	void Search(const string &);
	void Insert(const string &, const string &);
	void Modify(const string &, const string &);
	void Remove(const string &);
	void Save();

};


// DEFINITION

void DictionaryInterface::Tokenizer(const string &l, string &w, string &d)
{
	int lent = int(l.size());
	for (int i = 0; i < lent - 2; i++) {
		if (l[i] == ' ' && l[i + 1] == ' ') {
			w = l.substr(0, i);
			d = l.substr(i + 2, lent - w.length());
			break;
		}
	}
}


void DictionaryInterface::ReadFile(const string &s) {
	fstream file;
	//Oxford English Dictionary
	file.open(s, ios::in);
	string line, key1, value1, key2, value2;

	do {
		if (key2 == "") {
			getline(file, line);
			if (line == "" || line.size() < 4) continue;
			Tokenizer(line, key1, value1);
			transform(key1.begin(), key1.end(), key1.begin(), ::tolower);
		}
		else {
			key1 = key2;
			value1 = value2;
			key2.clear(); value2.clear();
		}

		bool flag = 0;
		// 0: no Usage
		// 1: have Usage

		if (!file.eof()) {
			do {
				line.clear();
				getline(file, line);
			} while (!file.eof() && (line == "" || line.size() < 4));

			if (line.size() > 3) { // blank line 
				Tokenizer(line, key2, value2);
				transform(key2.begin(), key2.end(), key2.begin(), ::tolower);
				if (key2 == "usage") {
					value1 = value1 + " (Usage: " + value2 + ").";
					flag = 1;
				}
				else flag = 0;
			}
		}
		data.insert(key1, value1);
		if (flag) {
			key2.clear();
			value2.clear();
		}
	} while (!file.eof());
	file.close();
}



void DictionaryInterface::Search(const string &k)
{
	string key = k;
	transform(key.begin(), key.end(), key.begin(), ::tolower);
	string ans = data.search(key);
	if (ans == "") cout << "NOT FOUND!";
	else cout << "Definition: " << ans;
}


void DictionaryInterface::Insert(const string &k, const string &v)
{
	data.insert(k, v);
	cout << "INSERT SUCCESSFUL!";
}


void DictionaryInterface::Modify(const string &k, const string &v)
{

	bool ans = data.modify(k, v);
	if (ans) cout << "MODIFY SUCCESSFUL!";
	else cout << "NOT FOUND!";
}


void DictionaryInterface::Remove(const string &k)
{
	string ans = data.search(k);
	if (ans == "") cout << "The word \"" << k << "\" does not exist.";
	else {
		data.remove(k);
		cout << "REMOVE SUCCESSFUL!";
	}
}


void DictionaryInterface::Save()
{
	fstream file;
	//freopen("Output_Dictionary.txt", "w", stdout);
	file.open("Output_Dictionary.txt", ios::out);
	data.inorderTraversal(file);
	//freopen("CON", "w", stdout);
	file.close();
	cout << "SAVED current Dictionary to file Output_Dictionary.txt";
}





#endif /* DICTIONARY_H */

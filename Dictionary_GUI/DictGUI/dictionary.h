#ifndef DICTIONARY_H
#define DICTIONARY_H

#include "hashtable.h"
#include <string>
#include <algorithm>



class Dictionary {
private:
    HashTable data;

public:
    Dictionary() {}
    ~Dictionary() { Clear(); }
    void Clear() { data.clear(); }

    void Tokenizer(const string &l, string &w, string &d)
    {
        size_t lent = l.length();
        for (size_t i = 0; i < lent - 2; i++) {
            if (l[i] == ' ' && l[i + 1] == ' ') {
                w = l.substr(0, i);
                d = l.substr(i + 2, lent - w.length());
                break;
            }
        }
    }

    bool ReadFile(const string &s) {
        fstream file;
        //Oxford English Dictionary
        file.open(s, ios::in);
        if (file.fail())
            return 0;
        string line, key1, key2, value1, value2;
        do {
            if (key2 == "") {
                getline(file, line);
                if (line == "" || line.size() < 6) continue;
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
                } while (!file.eof() && (line == "" || line.size() < 6));

                if (line.size() > 5) { // unuseful line
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
        return 1;
    }



    string Search(const string &k)
    {
        string key = k;
        transform(key.begin(), key.end(), key.begin(), ::tolower);
        return data.search(key);
    }


    void Insert(const string &k, const string &v)
    {
        data.insert(k, v);
    }


    bool Modify(const string &k, const string &v)
    {
        return data.modify(k, v);
    }


    void Remove(const string &k)
    {
        data.remove(k);
    }


    bool Save(const string &s)
    {
        fstream file;
        //freopen("Output_Dictionary.txt", "w", stdout);
        file.open(s, ios::out);
        if (file.fail()) return 0;
        data.traversal(file);
        //freopen("CON", "w", stdout);
        file.close();
        return 1;
    }

};

#endif // DICTIONARY_H

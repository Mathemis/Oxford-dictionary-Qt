#include <iostream>
#include <functional>
#include <algorithm>
#include <string>
#include <fstream>
using namespace std;
#define MAX 40000


void Tokenizer(const string &l, string &w, string &d)
{
    int lent = l.length();
    for (int i = 0; i < lent - 2; i++) {
        if (l[i] == ' ' && l[i + 1] == ' ') {
            w = l.substr(0, i);
            d = l.substr(i + 2, lent - w.length());
            break;
        }
    }
}

unsigned long hashCode(string s)
{
    unsigned long hash = 5831;
    int i = 0;
    while (i < s.size())
        hash = ((hash << 5) + hash) + s[i++];//hash * 33 + s[i++];
    return hash % MAX;
}

int main()
{
    int check[MAX] = {0}, t;


    fstream inFile, outFile;
    //Oxford English Dictionary
    inFile.open("Oxford English Dictionary.txt", ios::in);
    string line, key1, value1, key2 = "", value2;
    outFile.open("out.txt", ios::out);
    int count = 0;
    do {
        if (key2 == "") {
            getline(inFile, line);
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

        if (!inFile.eof()) {
            do {
                line.clear();
                getline(inFile, line);
            } while (!inFile.eof() && (line == "" || line.size() < 6));

            if (line.size() > 4) { // unuseful line
                Tokenizer(line, key2, value2);
                transform(key2.begin(), key2.end(), key2.begin(), ::tolower);
                if (key2 == "usage") {
                    value1 = value1 + " (Usage: " + value2 + ").";
                    flag = 1;
                }
                else flag = 0;
            }
        }
        t = hashCode(key1);
        check[t]++;
        outFile << ++count << ",  " << t << " : " << key1 << "\n\n";
        if (flag) {
            key2.clear();
            value2.clear();
        }
    } while (!inFile.eof());

    inFile.close();
    outFile.close();


    int dem[31] = {0};
    for (int i = 0; i < MAX; ++i)
        for (int j = 0; j < 31; ++j)
            if (check[i] > j) dem[j]++;
    cout << dem[0] << endl;
    for (int j = 0; j < 30; ++j)
        cout << j+1 << ": " << dem[j]-dem[j+1] << endl;

    return 0;
}

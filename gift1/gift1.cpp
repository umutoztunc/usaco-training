/*
ID: umutozt1 
TASK: gift1
LANG: C++14                 
*/
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    ofstream fout("gift1.out");
    ifstream fin("gift1.in");
    int np;
    fin >> np;
    unordered_map<string, int> balances;
    vector<string> names;
    for (int i = 0; i < np; ++i) {
        string name;
        fin >> name;
        balances.insert({name, 0});
        names.push_back(name);
    }
    for (int i = 0; i < np; ++i) {
        string giver;
        fin >> giver;
        int total_amount;
        int ng;
        fin >> total_amount >> ng;
        if (total_amount == 0 || ng == 0)
            continue;
        int shared_amount = total_amount / ng;
        for (int j = 0; j < ng; ++j) {
            string name;
            fin >> name;
            balances[name] += shared_amount;
        }
        balances[giver] -= shared_amount * ng;
    }
    for (const auto &name : names) {
        fout << name << " " << balances[name] << endl;
    }
    return 0;
}

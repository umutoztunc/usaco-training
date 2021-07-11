/*
ID: umutozt1 
TASK: milk
LANG: C++14                 
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ofstream fout("milk.out");
    ifstream fin("milk.in");
    int N, M;
    fin >> N >> M;
    vector<pair<int, int>> farmers(M);
    for (int i = 0; i < M; ++i) {
        fin >> farmers[i].first >> farmers[i].second;
    }
    sort(farmers.begin(), farmers.end());
    int cost = 0;
    for (int i = 0; i < M && N > 0; ++i) {
        int amount = (N >= farmers[i].second) ? farmers[i].second : N;
        cost += amount * farmers[i].first;
        N -= amount;
    }
    fout << cost << endl;
    return 0;
}

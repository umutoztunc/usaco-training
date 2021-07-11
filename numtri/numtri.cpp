/*
ID: umutozt1 
TASK: numtri
LANG: C++14                 
*/
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    ofstream fout("numtri.out");
    ifstream fin("numtri.in");
    int n;
    fin >> n;
    vector<vector<int>> rows(n);
    for (int i = 0; i < n; ++i) {
        rows[i].resize(i + 1);
        for (int j = 0; j < i + 1; ++j) {
            fin >> rows[i][j];
        }
    }
    for (int i = n - 2; i >= 0; --i) {
        for (int j = 0; j < i + 1; ++j) {
            rows[i][j] += max(rows[i + 1][j], rows[i + 1][j + 1]);
        }
    }
    fout << rows[0][0] << endl;
    return 0;
}

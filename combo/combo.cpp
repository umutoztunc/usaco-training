/*
ID: umutozt1 
TASK: combo
LANG: C++14                 
*/
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int distance(int a, int b, int n) {
    int d1 =  a - b;
    int d2 = b - a;
    if (d1 < 0)
        d1 += n;
    if (d2 < 0)
        d2 += n;
    return min(d1, d2);
}

bool close_enough(const vector<int> &v1, const vector<int> &v2, int n) {
    for (int i = 0; i < 3; ++i) {
        if (distance(v1[i], v2[i], n) > 2)
            return false;
    }
    return true;
}

int main() {
    ofstream fout("combo.out");
    ifstream fin("combo.in");
    int n;
    fin >> n;
    vector<int> john(3);
    vector<int> master(3);
    fin >> john[0] >> john[1] >> john[2];
    fin >> master[0] >> master[1] >> master[2];
    int valid = 0;
    for (int a = 1; a <= n; ++a) {
        for (int b = 1; b <= n; ++b) {
            for (int c = 1; c <= n; ++c) {
                vector<int> key{a, b, c};
                if (close_enough(key, john, n) || close_enough(key, master, n))
                    ++valid;
            }
        }
    }
    fout << valid << endl;
    return 0;
}

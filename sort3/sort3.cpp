/*
ID: umutozt1 
TASK: sort3
LANG: C++14                 
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ofstream fout("sort3.out");
    ifstream fin("sort3.in");
    int N;
    fin >> N;
    int swaps = 0;
    int counts[4] = {0};
    vector<int> records;
    records.reserve(N);
    for (int i = 0; i < N; ++i) {
        int r;
        fin >> r;
        ++counts[r];
        records.push_back(r);
    }

    int start2 = counts[1];
    int start3 = start2 + counts[2];

    // Order 1s.
    int i2 = start2;
    int i3 = start3;
    int j = -1;
    for (int i = 0; i < counts[1]; ++i) {
        if (records[i] == 1)
            continue;
        if (records[i] == 2) {
            // Search among 2s.
            while (i2 < start3 && records[i2] != 1)
                ++i2;
            if (i2 < start3) {
                j = i2++;
            } else {
                // Search among 3s.
                while (i3 < N && records[i3] != 1)
                    ++i3;
                j = i3++;
            }
        } else {
            // Search among 3s.
            while (i3 < N && records[i3] != 1)
                ++i3;
            if (i3 < N) {
                j = i3++;
            } else {
                // Search among 2s.
                while (i2 < start3 && records[i2] != 1)
                    ++i2;
                j = i2++;
            }
        }
        ++swaps;
        swap(records[i], records[j]);
    }

    // Order 2s.
    j = start3;
    for (int i = start2; i < start3; ++i) {
        if (records[i] == 2)
            continue;
        while (j < N && records[j] != 2) {
            ++j;
        }
        ++swaps;
        swap(records[i], records[j++]);
    }

    fout << swaps << endl;
    return 0;
}

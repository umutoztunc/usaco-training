/*
ID: umutozt1 
TASK: skidesign
LANG: C++14                 
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>

using namespace std;


int get_cost(vector<int> hills, const vector<int> &org) {
    int n = hills.size();
    int lhs = hills[0];
    int rhs = hills[n - 1];
    for (int i = 1; i < n - 1; ++i) {
        if (hills[i] < lhs)
            hills[i] = lhs;
        else if (hills[i] > rhs)
            hills[i] = rhs;
    }
    int cost = 0;
    for (int i = 0; i < n; ++i) {
        cost += pow(abs(org[i] - hills[i]), 2);
    }
    return cost;
}

int get_cost(vector<int> &hills, const vector<int> &org, int diff) {
    int cost = numeric_limits<int>::max();
    int n = hills.size();
    hills[0] += diff;
    for (int i = 0; i <= diff; ++i) {
        cost = min(cost, get_cost(hills, org));
        --hills[0];
        --hills[n - 1];
    }
    return cost;
}

int main() {
    ofstream fout("skidesign.out");
    ifstream fin("skidesign.in");
    int n;
    fin >>n;
    vector<int> hills(n);
    for (int i = 0; i < n; ++i)
        fin >> hills[i];
    sort(hills.begin(), hills.end());
    vector<int> org = hills;
    int diff = hills[n - 1] - hills[0];
    if (diff <= 17) {
        fout << 0 << endl;
        return 0;
    }
    int cost = get_cost(hills, org, diff - 17);
    fout << cost << endl;
    return 0;
}

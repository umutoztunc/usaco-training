/*
ID: umutozt1 
TASK: milk2
LANG: C++14                 
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

bool is_intersect(int end, const pair<int, int> &interval) {
    return interval.first <= end;
}

int main() {
    ofstream fout("milk2.out");
    ifstream fin("milk2.in");
    int n;
    fin >> n;
    vector<pair<int, int>> intervals(n);
    for (int i = 0; i < n; ++i) {
        fin >> intervals[i].first >> intervals[i].second;
    }
    sort(intervals.begin(), intervals.end());
    int start = intervals[0].first;
    int end = intervals[0].second;
    int longest_at_least_one = end - start;
    int longest_no_cows = 0;
    for (int i = 1; i < n; ++i) {
        if (is_intersect(end, intervals[i])) {
            end = max(end, intervals[i].second);
            continue;
        }
        longest_at_least_one = max(longest_at_least_one, end - start);
        longest_no_cows = max(longest_no_cows, intervals[i].first - end);
        start = intervals[i].first;
        end = intervals[i].second;
    }
    longest_at_least_one = max(longest_at_least_one, end - start);
    fout << longest_at_least_one << " " << longest_no_cows << endl;
    return 0;
}

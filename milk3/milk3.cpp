/*
ID: umutozt1 
TASK: milk3
LANG: C++14                 
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <cstring>

using namespace std;

vector<int> pour(const vector<int> &buckets, const vector<int> &capacities,
                 int from, int to) {
    vector<int> new_buckets = buckets;
    int total = new_buckets[from] + new_buckets[to];
    new_buckets[to] = min(total, capacities[to]);
    new_buckets[from] = total - new_buckets[to];
    return new_buckets;
}

void dfs(vector<int> buckets, const vector<int> &capacities,
         bool visited[21][21][21], set<int> &result) {
    visited[buckets[0]][buckets[1]][buckets[2]] = true;
    if (buckets[0] == 0)
        result.insert(buckets[2]);
    for (int i = 0; i < 2; ++i) {
        for (int j = i + 1; j < 3; ++j) {
            vector<int> tmp = pour(buckets, capacities, i, j);
            if (!visited[tmp[0]][tmp[1]][tmp[2]])
                dfs(tmp, capacities, visited, result);
            tmp = pour(buckets, capacities, j, i);
            if (!visited[tmp[0]][tmp[1]][tmp[2]])
                dfs(tmp, capacities, visited, result);
        }
    }
}

int main() {
    ofstream fout("milk3.out");
    ifstream fin("milk3.in");
    vector<int> buckets(3);
    vector<int> capacities(3);
    for (int i = 0; i < 3; ++i)
        fin >> capacities[i];
    buckets[2] = capacities[2];
    bool visited[21][21][21];
    memset(visited, 0, sizeof(visited));
    set<int> result;
    dfs(buckets, capacities, visited, result);
    for (auto it = result.begin(); it != result.end(); ++it) {
        fout << *it;
        if (it == prev(result.end()))
            fout << endl;
        else
            fout << " ";
    }
    return 0;
}

/*
ID: umutozt1 
TASK: wormhole
LANG: C++14                 
*/
#include <iostream>
#include <fstream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

using pii = pair<int, int>;

bool check_loop_dfs(pii wh,
                    const map<pii, pii> &wh_map,            
                    const unordered_map<int, set<int>> &same_line) {
    set<pii> visited;
    while (visited.count(wh) == 0) {
        visited.insert(wh);
        wh = wh_map.at(wh);
        auto next = upper_bound(same_line.at(wh.second).begin(),
                                same_line.at(wh.second).end(), wh.first);
        if (next == same_line.at(wh.second).end())
            return false;
        wh.first = *next;
    }
    return true;
}

bool check_loop(const vector<pii> &wormholes,
                const map<pii, pii> &wh_map,
                const unordered_map<int, set<int>> &same_line) {
    for (const auto& start : wormholes) {
        if (check_loop_dfs(start, wh_map, same_line))
            return true;
    }
    return false;
}

void bruteforce(const vector<pii> &wormholes,
                map<pii, pii> &wh_map,
                const unordered_map<int, set<int>> &same_line, int &count) {
    if (wh_map.size() == wormholes.size()) {
        if (check_loop(wormholes, wh_map, same_line))
            ++count;
        return;
    }
    int wh_i = -1;
    for (int i = 0; i < wormholes.size(); ++i) {
        if (wh_map.count(wormholes[i]) == 0) {
            wh_i = i;
            break;
        }
    }
    for (int wh_j = 0; wh_j < wormholes.size(); ++wh_j) {
        if (wh_j == wh_i || wh_map.count(wormholes[wh_j]) > 0)
            continue;
        wh_map[wormholes[wh_i]] = wormholes[wh_j];
        wh_map[wormholes[wh_j]] = wormholes[wh_i];
        bruteforce(wormholes,wh_map, same_line, count);
        wh_map.erase(wormholes[wh_i]);
        wh_map.erase(wormholes[wh_j]);
    }
}

int main() {
    ofstream fout("wormhole.out");
    ifstream fin("wormhole.in");
    int n;
    fin >> n;
    map<pii, pii> wh_map;
    vector<pii> wormholes;
    wormholes.reserve(n);
    unordered_map<int, set<int>> same_line;
    for (int i = 0; i < n; ++i) {
        int x, y;
        fin >> x >> y;
        wormholes.push_back({x, y});
        same_line[y].insert(x);
    }
    int count = 0;
    bruteforce(wormholes, wh_map, same_line, count);
    fout << count << endl;
    return 0;
}

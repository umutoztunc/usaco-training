/*
ID: umutozt1 
TASK: ariprog
LANG: C++14                 
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

void search(vector<pair<int, int>> &results, const vector<int> &s,
            const vector<bool> &exist, int n) {
    for (int i = 0; i < s.size(); ++i) { // 30 000
        int a = s[i];
        for (int j = i + 1; j < s.size(); ++j) {
            int b = s[j] - a;
            bool valid = true;
            for (int i = n - 1; i > 1; --i) {
                int val = a + i * b;
                if (val >= exist.size() || !exist[a + i * b]) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                results.push_back({b, a});
            }
        }
    }
    sort(results.begin(), results.end());
}

int main() {
    ofstream fout("ariprog.out");
    ifstream fin("ariprog.in");
    int n, m;
    fin >> n >> m;
    vector<pair<int, int>> results;
    vector<bool> exist(2 * m * m + 1);
    vector<int> s;
    for (int p = 0; p <= m; ++p) {
        for (int q = p; q <= m; ++q) {
            int val = p * p + q * q;
            if (exist[val])
                continue;
            s.push_back(val);
            exist[val] = true;
        }
    }
    sort(s.begin(), s.end());
    search(results, s, exist, n) ;
    if (results.empty()) {
        fout << "NONE" << endl;
        return 0;
    }
    for (const auto &r : results)
        fout << r.second << " " << r.first << endl;
    return 0;
}

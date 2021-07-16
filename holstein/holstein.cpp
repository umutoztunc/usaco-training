/*
ID: umutozt1 
TASK: holstein
LANG: C++14                 
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

bool is_valid_subset(const vector<int> &subset,
                     const vector<vector<int>> &feeds, vector<int> needs) {
  for (int i : subset) {
    for (int j = 0; j < needs.size(); ++j)
      needs[j] -= feeds[i][j];
  }
  for (int n : needs) {
    if (n > 0)
      return false;
  }
  return true;
}

vector<int> find_solution(const vector<vector<vector<int>>> &subsets,
                          const vector<vector<int>> &feeds,
                          const vector<int> &needs) {
  for (int size = 1; size < subsets.size(); ++size) {
    for (const auto &subset : subsets[size]) {
      if (is_valid_subset(subset, feeds, needs))
        return subset;
    }
  }
  return {};
}

vector<vector<vector<int>>> generate_subsets(const vector<vector<int>> &feeds) {
  int G = feeds.size();
  int V = feeds[0].size();
  vector<vector<vector<int>>> ans(G+1);
  for (int i = 0; i < G; ++i)
    ans[1].push_back({i});
  for (int size = 2; size <= G; ++size) {
    for (const vector<int> &subset : ans[size - 1]) {
      for (int j = subset[subset.size() - 1] + 1; j < G; ++j) {
        auto new_subset = subset;
        new_subset.push_back(j);
        ans[size].push_back(new_subset);
      }
    }
  }
  return ans;
}

int main() {
  ofstream fout("holstein.out");
  ifstream fin("holstein.in");
  int V;
  fin >> V;
  vector<int> needs(V);
  for (int i = 0; i < V; ++i) {
    fin >> needs[i];
  }
  int G;
  fin >> G;
  vector<vector<int>> feeds(G, vector<int>(V));
  for (int i = 0; i < G; ++i) {
    for (int j = 0; j < V; ++j) {
      fin >> feeds[i][j];
    }
  }
  auto subsets = generate_subsets(feeds);
  auto solution = find_solution(subsets, feeds, needs);
  fout << solution.size();
  for (int i = 0; i < solution.size(); ++i) {
    fout << " " << (solution[i] + 1);
  }
  fout << endl;
  return 0;
}

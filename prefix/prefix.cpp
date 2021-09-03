/*
ID: umutozt1
TASK: prefix
LANG: C++14
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <queue>
#include <memory>

using namespace std;

struct TrieNode {
  bool is_primitive;
  shared_ptr<TrieNode> children[26];
};

struct Trie {
  shared_ptr<TrieNode> root;

  void insert(string s) {
    auto node = root;
    for (char c : s) {
      if (!node->children[c - 'A'])
        node->children[c - 'A'] = make_shared<TrieNode>();
      node = node->children[c - 'A'];
    }
    node->is_primitive = true;
  }

  Trie() : root(make_shared<TrieNode>()) {}
};

int longest_prefix(const string &s, const Trie &trie) {
  queue<int> q;
  unordered_set<int> visited;

  q.push(0);
  visited.insert(0);
  int longest = 0;

  while (!q.empty()) {
    int i = q.front();
    q.pop();

    if (i >= s.size())
      continue;

    auto node = trie.root;
    while (node && node->children[s[i] - 'A']) {
      node = node->children[s[i++] - 'A'];
      if (node->is_primitive && !visited.count(i)) {
        longest = max(i, longest);
        visited.insert(i);
        q.push(i);
      }
    }
  }
  return longest;
}

int main() {
  ofstream fout("prefix.out");
  ifstream fin("prefix.in");
  Trie trie;
  string s, p, line;
  while (fin >> p) {
    if (p == ".") {
      fin >> s;
      break;
    }
    trie.insert(p);
  }
  getline(fin, line); // Clear trailing newline
  while (getline(fin, line)) {
    s += line;
  }
  int longest = longest_prefix(s, trie);
  fout << longest << endl;
  return 0;
}

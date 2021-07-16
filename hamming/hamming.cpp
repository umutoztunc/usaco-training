/*
ID: umutozt1
TASK: hamming
LANG: C++14
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <limits>

using namespace std;

int count_ones(int x) {
  int ones = 0;
  while (x > 0) {
    ++ones;
    x &= x - 1;
  }
  return ones;
}

int hamming_distance(int x, int y) {
  int diff = x ^ y;
  return count_ones(diff);
}

int min_hamming_distance(int x, const vector<int> &codewords) {
  int mind = numeric_limits<int>::max();
  for (int cw : codewords) {
    int d = hamming_distance(x, cw);
    mind = min(mind, d);
  }
  return mind;
}

vector<int> find_codewords(int N, int B, int D) {
  vector<int> codewords{0};
  if (N == 1)
    return codewords;
  int max_value = 1 << B;
  for (int x = 1; x < max_value; ++x) {
    if (min_hamming_distance(x, codewords) >= D) {
      codewords.push_back(x);
      if (codewords.size() >= N)
        break;
    }
  }
  return codewords;
}

int main() {
  ofstream fout("hamming.out");
  ifstream fin("hamming.in");
  int N, B, D;
  fin >> N >> B >> D;
  vector<int> codewords = find_codewords(N, B, D);
  for (int i = 0; i < codewords.size(); ++i) {
    fout << codewords[i];
    if (i % 10 == 9 || i == codewords.size() - 1)
      fout << endl;
    else
      fout << " ";
  }
  return 0;
}

/*
ID: umutozt1
TASK: subset
LANG: C++14
*/
#include <iostream>
#include <fstream>
#include <unordered_map>

using namespace std;

unordered_map<long long, unsigned int> memo;

unsigned int count_partitions(int p1, int p2, int n) {
  if (n == 0) 
    return p1 == p2;

  long long key = (p1 << 24) | (p2 << 8) | n;

  if (memo.find(key) != memo.end())
    return memo[key];

  int res = count_partitions(p1 + n, p2, n - 1) +
    count_partitions(p1, p2 + n, n - 1);
  memo[key] = res;
  return res;
}


int main() {
  ofstream fout("subset.out");
  ifstream fin("subset.in");
  int n;
  fin >> n;
  unsigned int count = count_partitions(0, 0, n);
  fout << count / 2 << endl;
  return 0;
}

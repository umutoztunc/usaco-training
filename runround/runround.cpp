/*
ID: umutozt1
TASK: runround
LANG: C++14
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <set>

using namespace std;

bool is_runaround(unsigned int number) {
  stringstream ss;
  ss << number;
  string s = ss.str();
  if (s.find('0') != string::npos)
    return false;
  set<char> seen;
  int i = 0;
  for (int k = 0; k < s.size(); ++k) {
    if (seen.find(s[i]) != seen.end())
      return false;
    seen.insert(s[i]);
    i = (i + s[i] - '0') % s.size();
  }
  return i == 0;
}

int main() {
  ofstream fout("runround.out");
  ifstream fin("runround.in");
  unsigned int m;
  fin >> m;
  while (!is_runaround(++m)) {}
  fout << m << endl;
  return 0;
}

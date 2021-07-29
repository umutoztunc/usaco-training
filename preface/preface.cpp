/*
ID: umutozt1
TASK: preface
LANG: C++14
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<pair<int, string>> values{
  {1000, "M"},
  {900, "CM"},
  {500, "D"},
  {400, "CD"},
  {100, "C"},
  {90, "XC"},
  {50, "L"},
  {40, "XL"},
  {10, "X"},
  {9, "IX"},
  {5, "V"},
  {4, "IV"},
  {1, "I"}
};

void update_counts(int number, unordered_map<char, int> &count_map) {
  while (number > 0) {
    for (auto p : values) {
      if (p.first <= number) {
        number -= p.first;
        for (char c : p.second)
          ++count_map[c];
        break;
      }
    }
  }
}


int main() {
  ofstream fout("preface.out");
  ifstream fin("preface.in");
  int n;
  fin >> n;
  unordered_map<char, int> count_map;
  for (int page = 1; page <= n; ++page)
    update_counts(page, count_map);
  for (char c : "IVXLCDM") {
    int count = count_map[c];
    if (count > 0)
      fout << c << " " << count << endl;
  }
  return 0;
}

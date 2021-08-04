/*
ID: umutozt1
TASK: lamps
LANG: C++14
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

bool is_buttons_possible(int buttons, int C) {
  int on_count = __builtin_popcount(buttons);
  if (on_count > C)
    return false;
  return (on_count & 1) == (C & 1);
}

void button1(vector<int> &lamps) {
  for (int &lamp : lamps)
    lamp ^= 1;
}

void button2(vector<int> &lamps) {
  for (int i = 0; i < lamps.size(); i += 2)
    lamps[i] ^= 1;
}

void button3(vector<int> &lamps) {
  for (int i = 1; i < lamps.size(); i += 2)
    lamps[i] ^= 1;
}

void button4(vector<int> &lamps) {
  for (int i = 0; i < lamps.size(); i += 3)
    lamps[i] ^= 1;
}

void find_final_state(const vector<bool> &buttons, const vector<int> &on_lamps,
                      const vector<int> &off_lamps, int N,
                      vector<vector<int>> &final_states) {
  vector<int> lamps(N, 1);
  if (buttons[1])
    button1(lamps);
  if (buttons[2])
    button2(lamps);
  if (buttons[3])
    button3(lamps);
  if (buttons[4])
    button4(lamps);
  for (int index : on_lamps) {
    if (lamps[index] == 0)
      return;
  }
  for (int index : off_lamps) {
    if (lamps[index] == 1)
      return;
  }
  final_states.push_back(lamps);
}

bool compare_states(const vector<int> &lhs, const vector<int> &rhs) {
  for (int i = 0 ; i < lhs.size(); ++i) {
    if (lhs[i] == rhs[i])
      continue;
    return lhs[i] < rhs[i];
  }
  return true;
}

int main() {
  ofstream fout("lamps.out");
  ifstream fin("lamps.in");
  int N, C;
  fin >> N >> C;
  vector<int> on_lamps;
  vector<int> off_lamps;
  // Read on lamps
  while (true) {
    int lamp;
    fin >> lamp;
    if (lamp == -1)
      break;
    on_lamps.push_back(lamp - 1);
  }
  // Read off lamps
  while (true) {
    int lamp;
    fin >> lamp;
    if (lamp == -1)
      break;
    off_lamps.push_back(lamp - 1);
  }

  vector<vector<int>> final_states;
  for (int i = 0; i < 16; ++i) {
    if (!is_buttons_possible(i, C))
      continue;
    vector<bool> buttons{
      false,
      i & (1 << 3),
      i & (1 << 2),
      i & (1 << 1),
      i & (1 << 0)
    };
    find_final_state(buttons, on_lamps, off_lamps, N, final_states);
  }
  sort(final_states.begin(), final_states.end(), compare_states);

  if (final_states.empty()) {
    fout << "IMPOSSIBLE" << endl;
    return 0;
  }

  for (const auto& state : final_states) {
    for (int lamp : state)
      fout << lamp;
    fout << endl;
  }
  return 0;
}

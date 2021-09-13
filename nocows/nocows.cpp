/*
ID: umutozt1
TASK: nocows
LANG: C++14
*/
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
  ofstream fout("nocows.out");
  ifstream fin("nocows.in");
  int N, K;
  fin >> N >> K;
  vector<vector<int>> dp(2 * N, vector<int>(K + 1));
  int m = 9901;
  dp[1][1] = 1;
  for (int n1 = 1; n1 < N; n1 += 2) {
    for (int n2 = 1; n2 <= n1; n2 += 2) {
      for (int k1 = 1; k1 < K; ++k1) {
        for (int k2 = 1; k2 < K; ++k2) {
          if (!dp[n1][k1] || !dp[n2][k2])
            continue;
          int count = dp[n1][k1] * dp[n2][k2] % m;
          if (n1 != n2)
            count = 2 * count % m;
          dp[1 + n1 + n2][1 + max(k1, k2)] += count;
          dp[1 + n1 + n2][1 + max(k1, k2)] %= m;
        }
      }
    }
  }
  fout << dp[N][K] << endl;
  return 0;
}

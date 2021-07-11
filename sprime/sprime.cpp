/*
ID: umutozt1 
TASK: sprime
LANG: C++14                 
*/
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

bool is_prime(int x) {
    if (x < 2)
        return false;
    for (int k = 2; k * k <= x; ++k) {
        if (x % k == 0)
            return false;
    }
    return true;
}

void get_sprimes(vector<int> &sprimes, int n, int x) {
    if (n == 0) {
        sprimes.push_back(x);
        return;
    }
    for (int d = (x == 0) ? 1 : 0; d <= 9; ++d) {
        int y = 10 * x + d;
        if (is_prime(y))
            get_sprimes(sprimes, n - 1, y);
    }
}

int main() {
    ofstream fout("sprime.out");
    ifstream fin("sprime.in");
    int n;
    fin >> n;
    vector<int> sprimes;
    get_sprimes(sprimes, n, 0);
    for (int sp : sprimes) {
        fout << sp << endl;
    }
    return 0;
}

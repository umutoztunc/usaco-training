/*
ID: umutozt1 
TASK: pprime
LANG: C++14                 
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;


bool is_prime(int x) {
    for (int k = 2; k * k <= x; ++k) {
        if (x % k == 0)
            return false;
    }
    return true;
}

void get_palindromes(vector<int> &digits, vector<int> &palindromes,
                     int digit_count) {
    if (digit_count / 2 == digits.size()) {
        int last_half = 0;
        int first_half = 0;
        for (int i = digits.size() - 1; i >= 0; --i) {
            last_half *= 10;
            last_half += digits[i];
        }
        for (int i = 0; i < digits.size(); ++i) {
            first_half *= 10;
            first_half += digits[i];
        }
        for (int d = 0; d <= 9; ++d) {
            int p = first_half * 10 + d;
            p *= pow(10, digits.size());
            p += last_half;
            palindromes.push_back(p);
        }
        if (digit_count % 2 == 0) {
            int p = first_half;
            p *= pow(10, digits.size());
            p += last_half;
            palindromes.push_back(p);
        }
        return;
    }
    for (int d = 0; d <= 9; ++d) {
        digits.push_back(d);
        get_palindromes(digits, palindromes, digit_count);
        digits.pop_back();
    }
}

vector<int> get_palindromes(int digit_count) {
    if (digit_count == 1)
        return {2, 3, 5, 7};
    vector<int> palindromes;
    vector<int> digits;
    for (int d = 1; d <= 9; d +=2) {
        digits.push_back(d);
        get_palindromes(digits, palindromes, digit_count);
        digits.pop_back();
    }
    return palindromes;
}

int main() {
    ofstream fout("pprime.out");
    ifstream fin("pprime.in");
    int a, b;
    fin >> a >> b;
    int min_digits = floor(log10(a)) + 1;
    int max_digits = floor(log10(b)) + 1;
    vector<int> pprimes;
    for (int digits = min_digits; digits <= max_digits; ++digits) {
        vector<int> palindromes = get_palindromes(digits);
        for (int p : palindromes) {
            if (a <= p && p <= b && is_prime(p))
                pprimes.push_back(p);
        }
        if (digits % 2 == 0)
            ++digits;
    }
    sort(pprimes.begin(), pprimes.end());
    for (int p : pprimes)
        fout << p << endl;
    return 0;
}

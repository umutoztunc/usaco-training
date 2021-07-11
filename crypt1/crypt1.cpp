/*
ID: umutozt1 
TASK: crypt1
LANG: C++14                 
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

bool has_valid_digits(int num, const vector<int> &digits) {
    while (num > 0) {
        int digit = num % 10;
        if (find(digits.begin(), digits.end(), digit) == digits.end())
            return false;
        num /= 10;
    }
    return true;
}

bool check(int a, int b, int c, int d, int e, const vector<int> &digits) {
    int abc = 100 * a + 10 * b + c;
    int p1 = abc * e;
    if (p1 < 100 || p1 > 999 || !has_valid_digits(p1, digits))
        return false;
    int p2 = abc * d; 
    if (p2 < 100 || p2 > 999 || !has_valid_digits(p2, digits))
        return false;
    int res = p1 + 10 * p2;
    return has_valid_digits(res, digits);
}


int main() {
    ofstream fout("crypt1.out");
    ifstream fin("crypt1.in");
    int n;
    fin >> n;
    vector<int> digits(n);
    for (int i = 0; i < n; ++i)
        fin >> digits[i];
    int count = 0;
    for (int a : digits) {
        for (int b : digits) {
            for (int c : digits) {
                for (int d : digits) {
                    for (int e : digits) {
                        if (check(a, b, c, d, e, digits))
                            ++count;
                    }
                }
            }
        }
    }
    fout << count << endl;
    return 0;
}

/*
ID: umutozt1 
TASK: dualpal
LANG: C++14                 
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

bool is_palindrome(const string &s) {
    for (int i = 0; i < s.size() / 2; ++i)
        if (s[i] != s[s.size() - 1 - i])
            return false;
    return true;
}

string to_base(int num, int base) {
    string res;
    while (num) {
        res += to_string(num % base);
        num /= base;
    }
    reverse(res.begin(), res.end());
    return res;
}

bool is_dualpalindrome(int num) {
    int count = 0;
    for (int base = 2; base <= 10; ++base) {
        if (is_palindrome(to_base(num, base))) {
            ++count;
            if (count >= 2)
                return true;
        }
    }
    return false;
}

int main() {
    ofstream fout("dualpal.out");
    ifstream fin("dualpal.in");
    int n, s;
    fin >> n >> s;
    ++s;
    while (n--) {
        while (!is_dualpalindrome(s))
            ++s;
        fout << s << endl;
        ++s;
    }
    return 0;
}

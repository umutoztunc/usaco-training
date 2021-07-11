/*
ID: umutozt1 
TASK: palsquare
LANG: C++14                 
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>

using namespace std;

char digits[20] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B',
                   'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

bool is_palindrome(const string &s) {
    for (int i = 0; i < s.size() / 2; ++i) {
        if (s[i] != s[s.size() - 1 - i])
            return false;
    }
    return true;
}

string to_base(int num, int base) {
    string result;
    while (num) {
        result += digits[num % base];
        num /= base;
    }
    reverse(result.begin(), result.end());
    return result;
}

int main() {
    ofstream fout("palsquare.out");
    ifstream fin("palsquare.in");
    int base;
    fin >> base;
    for (int i = 1; i <= 300; ++i) {
        string sqrt = to_base(i * i, base);
        if (!is_palindrome(sqrt))
            continue;
        fout << to_base(i, base) << " " << sqrt << endl;
    }
    return 0;
}

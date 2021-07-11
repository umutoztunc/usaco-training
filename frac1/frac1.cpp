/*
ID: umutozt1 
TASK: frac1
LANG: C++14                 
*/
#include <iostream>
#include <fstream>
#include <set>

using namespace std;

struct Fraction {
    int numerator;
    int denominator;

    Fraction(int n, int d) {
        numerator = n;
        denominator = d;
    }

    bool operator<(const Fraction &f) const {
        double val = (double) numerator / (double) denominator;
        double fval = (double) f.numerator / (double) f.denominator;
        return val < fval;
    }
};

int main() {
    ofstream fout("frac1.out");
    ifstream fin("frac1.in");
    int N;
    fin >> N;
    set<Fraction> fractions;
    fractions.insert(Fraction(0, 1));
    fractions.insert(Fraction(1, 1));
    for (int d = 2; d <= N; ++d) {
        for (int n = 1; n < d; ++n) {
            fractions.insert(Fraction(n, d));
        }
    }
    for (const auto &f : fractions) {
        fout << f.numerator << "/" << f.denominator << endl;
    }
    return 0;
}

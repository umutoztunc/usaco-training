/*
ID: umutozt1 
TASK: ride
LANG: C++14                 
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout("ride.out");
    ifstream fin("ride.in");
    string comet, group;
    fin >> comet >> group;
    int c_val = 1;
    int g_val = 1;
    for (char c : comet)
        c_val *= c - 'A' + 1;
    for (char c : group)
        g_val *= c - 'A' + 1;
    if (c_val % 47 == g_val % 47)
        fout << "GO" << endl;
    else
        fout << "STAY" << endl;
    return 0;
}

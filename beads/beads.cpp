/*
ID: umutozt1 
TASK: beads
LANG: C++14                 
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout("beads.out");
    ifstream fin("beads.in");
    int n;
    string beads;
    fin >> n >> beads;
    int max_count = 0;
    for (int i = 0; i < n; ++i) {
        int curr = i;
        int next = (i + 1) % n;
        if (beads[curr] == beads[next])
            continue;
        char curr_bead;
        char next_bead;
        if (beads[curr] == 'r' || beads[curr] == 'b') {
            curr_bead = beads[curr];
            next_bead = (curr_bead == 'r') ? 'b' : 'r';
        } else { // beads[curr] is 'w'
            next_bead = beads[next];
            curr_bead = (next_bead == 'r') ? 'b' : 'r';
        }
        int count = 0;
        for (int j = curr; beads[j] != next_bead;) {
            ++count;
            --j;
            if (j < 0)
                j = n - 1;
        }
        for (int j = next; beads[j] != curr_bead; j = (j + 1) % n)
            ++count;
        max_count = max(count, max_count);
    }
    if (max_count == 0 || max_count > n)
        max_count = n;
    fout << max_count << endl;
    return 0;
}

/*
ID: umutozt1 
TASK: barn1
LANG: C++14                 
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ofstream fout("barn1.out");
    ifstream fin("barn1.in");
    int M, S, C;
    fin >> M >> S >> C;
    vector<int> A(C);
    for (int i = 0 ; i < C; ++i)
        fin >> A[i];
    sort(A.begin(), A.end());
    vector<int> distances(C - 1);
    for (int i = 1; i < C; ++i)
        distances[i - 1] = A[i] - A[i - 1] - 1;
    sort(distances.begin(), distances.end(), greater<int>());
    int nonblocked = 0;
    for (int i = 0; i < M - 1 && i <  C - 1; ++i) 
        nonblocked += distances[i]; 
    nonblocked += A[0] - 1;
    nonblocked += S - A[C - 1];
    int blocked = S - nonblocked;
    fout << blocked << endl;
    return 0;
}

/*
ID: umutozt1 
TASK: transform
LANG: C++14                 
*/
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void print_pattern(const vector<vector<char>> &pattern) {
    for (const auto &row : pattern) {
        for (char c : row)
            cout << c;
        cout << endl;
    }
}

bool is_equal(const vector<vector<char>> &p1, const vector<vector<char>> &p2) {
    int n = p1.size();
    for (int i = 0; i < n; ++i) {
        if (p1[i] != p2[i])
            return false;
    }
    return true;
}

vector<vector<char>> rotate90(const vector<vector<char>> &pattern) {
    vector<vector<char>> res = pattern;
    int n = res.size();
    for (int col = 0; col < n; ++col)
        for (int row = n - 1; row >= 0; --row)
            res[col][n - 1 - row] = pattern[row][col];
    return res;
}
vector<vector<char>> rotate180(const vector<vector<char>> &pattern) {
    vector<vector<char>> res = rotate90(pattern);
    res = rotate90(res);
    return res;
}

vector<vector<char>> rotate270(const vector<vector<char>> &pattern) {
    vector<vector<char>> res = rotate180(pattern);
    res = rotate90(res);
    return res;
}

vector<vector<char>> reflect(const vector<vector<char>> &pattern) {
    vector<vector<char>> res = pattern;
    int n = res.size();
    for (int col = n - 1; col >= 0; --col)
        for (int row = 0; row < n; ++row)
            res[row][n - 1 - col] = pattern[row][col];
    return res;
}

bool try_1(const vector<vector<char>> &initial_pattern,
           const vector<vector<char>> &final_pattern) {
    auto tmp = rotate90(initial_pattern);
    return is_equal(tmp, final_pattern);   
}

bool try_2(const vector<vector<char>> &initial_pattern,
           const vector<vector<char>> &final_pattern) {
    auto tmp = rotate180(initial_pattern);
    return is_equal(tmp, final_pattern);    
}

bool try_3(const vector<vector<char>> &initial_pattern,
           const vector<vector<char>> &final_pattern) {
    auto tmp = rotate270(initial_pattern);
    return is_equal(tmp, final_pattern);    
}

bool try_4(const vector<vector<char>> &initial_pattern,
           const vector<vector<char>> &final_pattern) {
    auto tmp = reflect(initial_pattern);
    return is_equal(tmp, final_pattern);
}

bool try_5(const vector<vector<char>> &initial_pattern,
           const vector<vector<char>> &final_pattern) {
    auto reflected = reflect(initial_pattern);
    auto tmp = rotate90(reflected);
    if (is_equal(tmp, final_pattern))
        return true;
    tmp = rotate180(reflected);
    if (is_equal(tmp, final_pattern))
        return true;
    tmp = rotate270(reflected);
    return is_equal(tmp, final_pattern);
}

bool try_6(const vector<vector<char>> &initial_pattern,
           const vector<vector<char>> &final_pattern) {
    return equal(initial_pattern.begin(), initial_pattern.end(),
                 final_pattern.begin()); 
}

int main() {
    ofstream fout("transform.out");
    ifstream fin("transform.in");
    int n;
    fin >> n;
    vector<vector<char>> initial_pattern(n, vector<char>(n));
    vector<vector<char>> final_pattern(n, vector<char>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            fin >> initial_pattern[i][j];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            fin >> final_pattern[i][j];
    int result;
    if (try_1(initial_pattern, final_pattern))
        result = 1;
    else if (try_2(initial_pattern, final_pattern))
        result = 2;
    else if (try_3(initial_pattern, final_pattern))
        result = 3;
    else if (try_4(initial_pattern, final_pattern))
        result = 4;
    else if (try_5(initial_pattern, final_pattern))
        result = 5;
    else if (try_6(initial_pattern, final_pattern))
        result = 6;
    else
        result = 7;
    fout << result << endl;
    return 0;
}

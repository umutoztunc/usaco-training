/*
ID: umutozt1 
TASK: castle
LANG: C++14                 
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

int find_room(const vector<vector<int>> &castle, vector<vector<int>> &room,
              int i, int j, int room_id) {
    room[i][j] = room_id;
    int size = 1;
    if ((castle[i][j] & 1) == 0 && room[i][j - 1] == -1)
        size += find_room(castle, room, i, j - 1, room_id);
    if ((castle[i][j] & 2) == 0 && room[i - 1][j] == -1)
        size += find_room(castle, room, i - 1, j, room_id);
    if ((castle[i][j] & 4) == 0 && room[i][j + 1] == -1)
        size += find_room(castle, room, i, j + 1, room_id);
    if ((castle[i][j] & 8) == 0 && room[i + 1][j] == -1)
        size += find_room(castle, room, i + 1, j, room_id);
    return size;
}

pair<int, string> solve(const vector<vector<int>> &castle,
                        const vector<vector<int>> &room,
                        const vector<int> &room_size) {
    int largest = 0;
    int N = castle.size();
    int M = castle[0].size();
    int max_i = -1;
    int max_j = -1;
    bool north = false;
    for (int j = 0; j < M; ++j) {
        for (int i = N - 1; i >= 0; --i) {
            int curr_room = room[i][j];
            if (i - 1 >= 0 && room[i - 1][j] != curr_room) {
                int size = room_size[room[i - 1][j]] + room_size[curr_room];
                if (size > largest) {
                    largest = size;
                    max_i = i;
                    max_j = j;
                    north = true;
                }
            }
            if (j + 1 < M && room[i][j + 1] != curr_room) {
                int size = room_size[room[i][j + 1]] + room_size[curr_room];
                if (size > largest) {
                    largest = size;
                    max_i = i;
                    max_j = j;
                    north = false;
                }
            }
        }
    }
    ostringstream ss;
    ss << max_i + 1 << " " << max_j + 1 << " " << (north ? "N" : "E");
    return {largest, ss.str()};

}

int main() {
    ofstream fout("castle.out");
    ifstream fin("castle.in");
    int M, N;
    fin >> M >> N;
    vector<vector<int>> castle(N, vector<int>(M));
    vector<vector<int>> room(N, vector<int>(M, -1));
    vector<int> room_size;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            fin >> castle[i][j];
        }
    }
    int room_id = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (room[i][j] != -1)
                continue;
            room_size.push_back(find_room(castle, room, i, j, room_id++));
        }
    }
    int largest = *max_element(room_size.begin(), room_size.end());
    int largest_creatable = 0;
    pair<int, string> result = solve(castle, room, room_size);
    fout << room_size.size() << endl;
    fout << largest << endl;
    fout << result.first << endl;
    fout << result.second << endl;
    return 0;
}

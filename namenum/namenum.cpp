/*
ID: umutozt1 
TASK: namenum
LANG: C++14                 
*/
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>

using namespace std;

void find_names(const string &id, int index,
                const unordered_set<string> &names_available,
                const unordered_map<char, vector<char>> &digit_to_char,
                vector<string> &names, string &name) {
   if (index == id.size()) {
       if (names_available.find(name) != names_available.end())
           names.push_back(name);
       return;
   }
   auto item = digit_to_char.find(id[index]);
   if (item == digit_to_char.end())
       return;
   for (char c : item->second) {
       name.push_back(c);
       find_names(id, index + 1, names_available, digit_to_char, names, name);
       name.pop_back();
   }
}

int main() {
    ofstream fout("namenum.out");
    ifstream fin("namenum.in");
    string id;
    fin >> id;

    unordered_set<string> names_available;
    ifstream fdict("dict.txt");
    string name;
    while (fdict >> name)
        names_available.insert(name);

    unordered_map<char, vector<char>> digit_to_char {
        {'2', {'A', 'B', 'C'}},
        {'3', {'D', 'E', 'F'}},
        {'4', {'G', 'H', 'I'}},
        {'5', {'J', 'K', 'L'}},
        {'6', {'M', 'N', 'O'}},
        {'7', {'P', 'R', 'S'}},
        {'8', {'T', 'U', 'V'}},
        {'9', {'W', 'X', 'Y'}}
    };

    name = "";
    vector<string> names;
    find_names(id, 0, names_available, digit_to_char, names, name);
    for (auto n : names)
        fout << n << endl;
    if (names.empty())
        fout << "NONE" << endl;
    return 0;
}

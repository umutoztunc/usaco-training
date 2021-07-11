/*
ID: umutozt1 
TASK: friday
LANG: C++14                 
*/
#include <iostream>
#include <fstream>

using namespace std;

int year = 1900;
int month = 1;
int day13 = 0;

bool IsLeapYear() {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int DaysInMonth() {
    if (month == 4 || month == 6 || month == 9 || month == 11)
        return 30;
    else if (month == 2)
        return 28 + IsLeapYear();
    else
        return 31;
}

void NextDay13() {
    int days = DaysInMonth();
    day13 = (day13 + days) % 7;
    ++month;
    if (month == 13) {
        month = 1;
        ++year;
    }
}

int main() {
    ofstream fout("friday.out");
    ifstream fin("friday.in");
    int n;
    fin >> n;
    int freq[7] = {};
    int year_to_stop = year + n;
    while (year < year_to_stop) {
        ++freq[day13];
        NextDay13();
    }
    for (int i = 0; i < 7; ++i) {
        fout << freq[i];
        if (i != 6)
            fout << " ";
    }
    fout << endl;
    return 0;
}

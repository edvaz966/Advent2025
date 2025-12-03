#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <sstream>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[]) {
    string filename{};
    if (argc > 1) {
        filename = argv[1];
    }
    ifstream file{filename};
    string s{};
    long result{};
    while (getline(file, s)) {
        string number{};
        auto first_number = max_element(s.begin(), prev(s.end()));
        number += *first_number;
        auto second_number = max_element(next(first_number), s.end());
        number += *second_number;
        result += stoi(number);
        // cout << "line: " << s << " first_number: " << *first_number << " second_number: " << *second_number << endl;
    }
    cout << "Part1: " << result << endl;
    return 0;
}
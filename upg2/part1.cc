#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <sstream>
#include <algorithm>

using namespace std;

int main() {
    ifstream file{"puzzle_input"};
    string s{};
    long result{};
    while (getline(file, s, ',')) {
        ranges::replace(s, '-', ' ');
        stringstream ss{s};
        string start_id{};
        string end_id{};
        ss >> start_id >> end_id;
        cout << start_id << " : " << end_id << endl;
        for (long i{stol(start_id)}; i < stol(end_id) + 1; i++) {
            string id{to_string(i)};
            if (id.size() % 2 == 1) {continue;}
            if (id.substr(0, id.size()/2) == id.substr(id.size()/2, id.size())) {
                result += i;
            }
        }
    }
    cout << "Part1: " << result;
    return 0;
}
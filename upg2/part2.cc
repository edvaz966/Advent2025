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
            for (int ii{id.size()/2}; ii > 0; ii--) {
                string sub{id.substr(0,ii)};
                string comp{};
                for (int iii{0}; iii < id.size()/sub.size(); iii++) {
                    comp += sub;
                }
                if (comp == id) {
                    cout << "Values Added: " << comp << endl; 
                    result += i;
                    break;
                }
            }
        }
    }
    cout << "Part2: " << result;
    return 0;
}
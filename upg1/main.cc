#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream file{"puzzle_input"};
    // ifstream file{"test"};
    string s{};
    int current{50};
    int zero_times{};
    while (getline(file, s, '\n')) {
        if (s[0] == 'L') {
            current = ((current - stoi(s.substr(1, s.size()))) % 100);
        }
        else if (s[0] == 'R') {
            current = ((current + stoi(s.substr(1, s.size()))) % 100);
        }
        // cout << current << endl;
        if (current == 0) {zero_times++;}
    }
    cout << "Number of Zeroes: " << zero_times << endl;
    return 0;
}
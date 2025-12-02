#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    ifstream file{"puzzle_input"};
    string s{};
    int current{50};
    int zero_times{};
    int rot{};
    while (getline(file, s, '\n')) {
        int move{stoi(s.substr(1, s.size()))};
        zero_times += move/100;
        int current_prev{current};
        if (s[0] == 'L') {
            current -= move%100;
            if (current < 0) {
                current += 100;
                if (current_prev != 0) {
                    zero_times++;
                }
            }
        }
        else if (s[0] == 'R') {
            current += move%100;
            if (current == 100) {current = 0;}
            if (current > 100) {current -= 100;zero_times++;}
        }
        if (current == 0) {zero_times++;}
    }
    cout << "Number of Zeroes: " << zero_times << endl;
    return 0;
}
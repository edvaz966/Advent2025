#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    ifstream file{"test"};
    string s{};
    int current{50};
    int zero_times{};
    int rot{};
    while (getline(file, s, '\n')) {
        int move{stoi(s.substr(1, s.size()))};
        if (s[0] == 'L') {
            if ((current - move) < 0) {
                current = 100 + (current - move);
                zero_times++;
                zero_times += move/100;
            } else {
                current -= move;
            }
        }
        else if (s[0] == 'R') {
            if ((current + move) > 100) {
                current = (current + move) % 100;
                zero_times++;
                zero_times += move/100;
            } else {
                current += move;
            }
        }
        if (current == 0) {zero_times++;}
        cout << "Rotation: " << rot++ << " Current: " <<  current << " Move: " << move << " Move/100: " << move/100 << " zero_times: " << zero_times << endl; 
    }
    cout << "Number of Zeroes: " << zero_times << endl;
    return 0;
}
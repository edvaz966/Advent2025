#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <sstream>
#include <algorithm>
#include <vector>
#include <iterator>

using namespace std;
int main(int argc, char* argv[]) {
    string filename{};
    if (argc > 1) {
        filename = argv[1];
    }
    ifstream file{filename};
    string s{};
    long long result{};
    vector<pair<long long, long long>> fresh_ranges{};
    while (getline(file, s)) {
        if (s == "") {break;}
        stringstream ss{s};
        long long range_start{};
        long long range_end{};
        char temp{};
        ss >> range_start >> temp >> range_end;
        fresh_ranges.push_back(make_pair(range_start, range_end));
    }
    while (getline(file, s)) {
        long long id{stoll(s)};
        for (auto [start, end] : fresh_ranges) {
            if (start <= id && id <= end) {
                cout << id << " Id Fresh!" << endl;
                result++;
                break;
            }
        }
    }
    cout << "Part1: " << result << endl;
    return 0;
}
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <sstream>
#include <algorithm>
#include <vector>
#include <iterator>

using namespace std;

template <typename T>
void print_map(vector<T> toPrint) {
    for (auto row : toPrint) {
        ranges::copy(row, ostream_iterator<typename T::value_type>(cout));
        cout << endl;
    }
}


int main(int argc, char* argv[]) {
    string filename{};
    if (argc > 1) {
        filename = argv[1];
    }
    ifstream file{filename};
    string s{};
    long result{};
    vector<string> map{};
    vector<vector<int>> relationmap{};
    while (getline(file, s)) {
        map.push_back(s);
        relationmap.push_back(vector<int>(s.size(), 0));
    }
    // print_map(map);
    // print_map(relationmap);
    // const size_t _size{map.size()};
    // const size_t _size{map.size() - 1};
    for (size_t y{}; y < map.size(); y++) {
        for (size_t x{}; x < map.size(); x++) {
            // if (map[y][x] == '.') {continue;}
            if (x != 0 && map[y][x - 1] == '@') {relationmap[y][x]++;}
            if (x != 0 && y != 0 && map[y - 1][x - 1] == '@') {relationmap[y][x]++;}
            if (y != 0 && map[y - 1][x] == '@') {relationmap[y][x]++;}
            if (x != map.size() - 1 && y != 0 && map[y - 1][x + 1] == '@') {relationmap[y][x]++;}
            if (x != map.size() - 1 && map[y][x + 1] == '@') {relationmap[y][x]++;}
            if (x != map.size() - 1 && y !=  map.size() - 1 && map[y + 1][x + 1] == '@') {relationmap[y][x]++;}
            if (y !=  map.size() - 1 && map[y + 1][x] == '@') {relationmap[y][x]++;}
            if (x != 0 && y !=  map.size() - 1 && map[y + 1][x - 1] == '@') {relationmap[y][x]++;}
            // cout << "Position: (" << x << ", " << y << ")" << endl;
        }
        // cout << "Loop Y: " << y << endl;
    }
    print_map(relationmap);
    for (size_t y{}; y < map.size(); y++) {
        for (size_t x{}; x < map.size(); x++) {
            if (map[y][x] == '.') {continue;};
            if (relationmap[y][x] < 4) {result++;}
            // result = relationmap[y][x] < 4 ? result++ : result;
        }
        // cout << "Loop Y: " << y << endl;
    }
    cout << "Part1: " << result << endl;
    return 0;
}
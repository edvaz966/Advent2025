#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <sstream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <chrono>
#include <thread>


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
    vector<string> map{};
    vector<vector<int>> relationmap{};
    long result{};
    while (getline(file, s)) {
        map.push_back(s);
        relationmap.push_back(vector<int>(s.size(), 0));
    }
    while (true) {
    for (size_t y{}; y < map.size(); y++) {
        for (size_t x{}; x < map.size(); x++) {
            if (map[y][x] == '.') {continue;};
            if (x != 0 && map[y][x - 1] == '@') {relationmap[y][x]++;}
            if (x != 0 && y != 0 && map[y - 1][x - 1] == '@') {relationmap[y][x]++;}
            if (y != 0 && map[y - 1][x] == '@') {relationmap[y][x]++;}
            if (x != map.size() - 1 && y != 0 && map[y - 1][x + 1] == '@') {relationmap[y][x]++;}
            if (x != map.size() - 1 && map[y][x + 1] == '@') {relationmap[y][x]++;}
            if (x != map.size() - 1 && y !=  map.size() - 1 && map[y + 1][x + 1] == '@') {relationmap[y][x]++;}
            if (y !=  map.size() - 1 && map[y + 1][x] == '@') {relationmap[y][x]++;}
            if (x != 0 && y !=  map.size() - 1 && map[y + 1][x - 1] == '@') {relationmap[y][x]++;}
        }
    }
    // cout << "-------------------" << endl;
    // print_map(relationmap);
    for (size_t y{}; y < map.size(); y++) {
        for (size_t x{}; x < map.size(); x++) {
            if (map[y][x] == '.') {continue;};
            if (relationmap[y][x] < 4) {
                result++;
                map[y][x] = '.';
            }
        }
    }
    bool do_it_nt{false};
    // cout << "No Rows has one left: " << ranges::all_of(relationmap, [&](auto row){return ranges::count_if(row, [&](int e){return e < 4 && e != 0;}) == 0;}) << endl;
    do_it_nt = ranges::all_of(relationmap, [&](auto row){return ranges::count_if(row, [&](int e){return e < 4 && e != 0;}) == 0;});
    if (do_it_nt) {break;}
    relationmap = vector<vector<int>>( map.size(), vector<int>(map.size(), 0));
    // std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }

    cout << "Part2: " << result << endl;
    return 0;
}
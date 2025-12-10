#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <sstream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <ranges>
#include <format>

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
    ranges::sort(fresh_ranges);
    auto remove_it = ranges::remove_if(fresh_ranges, [&](auto const& current){return ranges::any_of(fresh_ranges, [&](auto const& pair){return pair.first < current.first && current.second < pair.second;});});
    fresh_ranges.erase(remove_it.begin(), remove_it.end());
    cout << format("Lowest Value: {}", fresh_ranges.begin()->first) << endl;
    for (auto current{fresh_ranges.begin()}; current < fresh_ranges.end(); current++) {
        auto overlapping = ranges::find_last_if(fresh_ranges, [&](auto p){return p.first < current->second;});
        // cout << current->first << " to " << current->second << endl;
        if (current == overlapping.begin()) {
            // cout << "Found Current" << endl; 
        } else {
            // cout << "Found : (" << overlapping.begin()->first << ", " << overlapping.begin()->second << ")" << endl;
            current->second = overlapping.begin()->second;
            fresh_ranges.erase(overlapping.begin());
            ranges::sort(fresh_ranges);
            current = fresh_ranges.begin();
        }
    }
    for (auto [start, end] : fresh_ranges) {
        result += end - start + 1;
        cout << format("({}, {})",start,end) << endl;
    }
    cout << "Part1: " << result << endl;
    return 0;
}
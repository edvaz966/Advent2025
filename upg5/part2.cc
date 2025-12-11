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
    // ifstream file{"test"};
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
    for (size_t i{0}; i < fresh_ranges.size(); i++) {
        vector<pair<long long, long long>> find_max{};
        copy_if(next(fresh_ranges.begin(), i + 1), fresh_ranges.end(), back_inserter(find_max), [&](auto p){return p.first <= fresh_ranges[i].second;});
        if (!find_max.empty()) {
            fresh_ranges[i].second = *ranges::max_element(find_max | views::values);
        }
        auto remove_it = remove_if(fresh_ranges.begin()+i+1, fresh_ranges.end(), [&](auto const& current){return fresh_ranges[i].first <= current.first && current.second <= fresh_ranges[i].second;});
        if (remove_it != fresh_ranges.end()) {
            i = 0;
        }
        fresh_ranges.erase(remove_it, fresh_ranges.end());
    }
    for (auto [start, end] : fresh_ranges) {
        result += end - start + 1;
    }
    cout << "Part2: " << result << endl;
    return 0;
}
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <sstream>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[]) {
    string filename{};
    if (argc > 1) {
        filename = argv[1];
    }
    ifstream file{filename};
    string s{};
    long long result{};
    while (getline(file, s)) {
        size_t nofbat{12};
        string number{};
        string::iterator it{s.begin()};
        while (nofbat > 0) {
            it = max_element(it, prev(s.end(), (nofbat-- - 1)));
            number += *it;
            it++;
        }
        result += stoll(number);
    }
    cout << "Part2: " << result << endl;
    return 0;
}
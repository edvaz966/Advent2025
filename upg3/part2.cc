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
            // cout << "loop: " << 12 - nofbat << " span: " << string{it, prev(s.end(), nofbat)};
            it = max_element(it, prev(s.end(), (nofbat-- - 1)));
            // cout <<  " res: " << *it << endl;
            number += *it;
            it++;
            // if (it == prev(s.end(), nofbat)) {
            //     number += string{it,s.end()};
            // }
        }
        // cout << "line: " << s << " number: " << number << "number.size: " << number.size() << endl;
        result += stoll(number);
    }
    cout << "Part2: " << result << endl;
    return 0;
}
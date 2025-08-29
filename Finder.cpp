#include "Finder.h"
#include <vector>

using namespace std;

vector<int> Finder::findSubstrings(string s1, string s2) {
    vector<int> result;
    size_t searchStart = 0;
    string prefix;

    for (std::string::size_type i = 0; i < s2.size(); i++) {
        prefix += s2[i];
        size_t found = s1.find(prefix, searchStart);

        if (found != string::npos) {
            result.push_back(found);
            searchStart = found;
        } else {
            result.push_back(-1);
            break;
        }
    }

    for (std::string::size_type j = result.size(); j < s2.size(); j++) {
        result.push_back(-1);
    }

    return result;
}
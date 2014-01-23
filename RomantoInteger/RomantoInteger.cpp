//============================================================================
// Roman to Integer
// Given a roman numeral, convert it to an integer.
//
// Input is guaranteed to be within the range from 1 to 3999.
//============================================================================

#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<char, int> table = {
    {'M', 1000},
    {'D', 500},
    {'C', 100},
    {'L', 50},
    {'X', 10},
    {'V', 5},
    {'I', 1}
};

class Solution {
public:
    int romanToInt(string s) {
        int res = 0, N = s.size();
        for (int i = 0; i < N; i++) {
            if (i < N-1 && table[s[i]] < table[s[i+1]]) res -= table[s[i]];
            else res += table[s[i]];
        }
        return res;
    }
};

int main() {
    return 0;
}
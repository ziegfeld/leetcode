//============================================================================
// Given an integer, convert it to a roman numeral.
//
// Input is guaranteed to be within the range from 1 to 3999.
//============================================================================

#include <iostream>
#include <string>

using namespace std;

int ints[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
string romans[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };

class Solution {
public:
    string intToRoman(int num) {
        ostringstream os;
        for (int i = 0; i < 13; i++) {
            while (num >= ints[i]) {
                num -= ints[i];
                os << romans[i];
            }
        }
        return os.str();
    }
};

int main() {
    return 0;
}
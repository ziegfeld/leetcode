//============================================================================
// Given an integer, convert it to a roman numeral.
//
// Input is guaranteed to be within the range from 1 to 3999.
//============================================================================

#include <iostream>
#include <string>

using namespace std;

char table[] = {
    'I',  //  1
    'V', //  5
    'X', // 10
    'L', // 50
    'C', //100
    'D', // 500
    'M'  //1000
};

int ints[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
string romans[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };


class Solution {
public:
    string intToRoman(int num) {
        return intToRoman_anson627(num);
    }
    
    string intToRoman_anson627(int num) {
        ostringstream os;
        for (int i = 0; i < 13; i++) {
            while (num >= ints[i]) {
                num -= ints[i];
                os << romans[i];
            }
        }
        return os.str();
    }
    
    

    string intToRoman_My(int num) {
        string res = "";
        int weight = 10, i = 0;
        while (num>0){
            int_to_r_10(i++, num%10, res);
            num /= 10;
        }
        return res;
    }
    void int_to_r_10(int i, int digit, string &res){
        string val = "";
        if (digit>8) {
            // *val ++ = table[i * 2 ];ÈÈËÀ //1
            // *val ++ = table[i * 2 + 2]; //10
            val += table[i * 2 ];    // 1
            val += table[i * 2 + 2]; //10
        } else if (digit>=5) {
            val += table[i * 2 + 1]; // 5
            while (digit-- >5)
                val += table[i * 2]; // 1
        } else if (digit==4) {
            val += table[i * 2 ];    // 1
            val += table[i * 2 + 1]; // 5
        } else {
            while (digit-- >0)
                val += table[i * 2]; // 1
        }
        res = val + res;
    }
};

int main() {
    return 0;
}

//============================================================================
// The count-and-say sequence is the sequence of integers beginning as follows:
// 1, 11, 21, 1211, 111221, ...
//
// 1 is read off as "one 1" or 11.
// 11 is read off as "two 1s" or 21.
// 21 is read off as "one 2, then one 1" or 1211.
// Given an integer n, generate the nth sequence.
//
// Note: The sequence of integers will be represented as a string.
//============================================================================

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if (n < 1) return "";
        string res = "1";
        for (; n > 1; n--) {
            int N = res.size(), i = 0;
            ostringstream os;
            while (i < N) {
                int j = i;
                while (j < N && res[j] == res[i]) j++;
                os << (j-i) << res[i];
                i = j;
            }
            res = os.str();
        }
        return res;
    }
};

int main() {

    Solution sol;

    {
        for (int i = 1; i < 6; i++)
            cout << sol.countAndSay(i) << endl;
    }
    
    return 0;
}
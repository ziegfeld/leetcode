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
        string res = "1";
        for (; n > 1; n--) {
            ostringstream os;
            int N = res.size();
            for (int i = 0; i < N; i++) {
                int cnt = 1;
                while (i < N - 1 && res[i] == res[i + 1]) i++, cnt++;
                os << cnt << res[i];
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
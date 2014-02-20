//============================================================================
// PlusOne
// Given a number represented as an array of digits, plus one to the number.
// 
// Complexity:
// O(n)
//============================================================================

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        //vector<int> res = digits;
        int i = digits.size() - 1;
        for (; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++;
                break;
            }
            else digits[i] = 0;
        }
        // learn this: digits.insert(digits.begin(), 1);
        if (i == -1)
            digits.insert(digits.begin(), 1);
        return digits;
    }
};

int main() {
    return 0;
}

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
        int N = digits.size();
        for (int i = N - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++;
                return;
            }
            else {
                digits[i] = 0;
            }
        }
        vector<int> res(N + 1, 0);
        res[0] = 1;
        return res;
    }
};

int main() {
    return 0;
}

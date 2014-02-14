//============================================================================
// PlusOne
// Given a number represented as an array of digits, plus one to the number.
// 
// Complexity:
// O(n)
//============================================================================

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        vector<int> res = digits;
        int i = res.size() - 1;
        for (; i >= 0; i--) {
            if (res[i] < 9) {
                res[i]++;
                break;
            }
            else res[i] = 0;
        }
        if (i == -1) res.insert(res.begin(), 1);
        return res;
    }
};

int main() {
    return 0;
}

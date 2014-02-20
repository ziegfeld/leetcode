//============================================================================
// You are climbing a stair case. It takes n steps to reach to the top.
//
// Each time you can either climb 1 or 2 steps.
// In how many distinct ways can you climb to the top?
//
// Complexity:
// DP, O(n) time, O(n) space
// DP, O(n) time, O(1) space
// Matrix Pow, O(log(n)) time, O(1) space
//============================================================================
class Solution {
public:
    int climbStairs1(int n) {
        if (n<=2) return n;
        int curMin1 = 1;
        int curMin2 = 2;
        int i = 3;
        int res = 0;
        while (i<=n) {
            res = curMin2 + curMin1;
            curMin1 = curMin2;
            curMin2 = res;
            i++;
        }
        return res;
    }
    
    
    int climbStairs(int n) {
        climbStairs1(n);
    }
};
int main() {
    return 0;
}

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
    int climbStairs(int n) {
        return climbStairs3(n);
    }

    int climbStairs1(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = dp[1] = 1;
        for (int i = 2; i <= n; i++) dp[i] = dp[i - 1] + dp[i - 2];
        return dp[n];
    }

    int climbStairs2(int n) {
        int t1 = 1, t2 = 1, res = 1;
        for (int i = 2; i <= n; i++) {
            res = t1 + t2;
            t1 = t2;
            t2 = res;
        }
        return res;
    }

    int climbStairs3(int n) {
        vector<vector<int> > m = {
            { 1, 1 },
            { 1, 0 }
        };
        m = pow(m, n);
        return m[1][0] + m[1][1];
    }

    vector<vector<int> > pow(vector<vector<int> > & m, int n) {
        if (n == 1) return m;
        auto t = pow(m, n / 2);
        t = mul(t, t);
        if (n % 2 == 1) t = mul(t, m);
        return t;
    }

    vector<vector<int> > mul(vector<vector<int> > & a, vector<vector<int> > & b) {
        int n = a.size();
        vector<vector<int> > c(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    c[i][j] += a[i][k] * b[k][j];
                }
            }
        }
        return c;
    }
};

int main() {
    return 0;
}

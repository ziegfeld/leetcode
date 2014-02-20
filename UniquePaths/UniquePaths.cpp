//============================================================================
// Unique Paths
// A robot is located at the top-left corner of a m x n grid (marked 'Start'
// in the diagram below).
//
// The robot can only move either down or right at any point in time. The robot
// is trying to reach the bottom-right corner of the grid (marked 'Finish' in
// the diagram below).
//
// How many possible unique paths are there?
//
// Complexity:
// DP, O(m*n) time, O(1) space
// DP, O(m*n) time, O(n) space
// Math, O(n) time, O(1) space
//============================================================================

#include <iostream>
#include <cstring>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        //return uniquePaths3(m, n);
        return pascalTria(m,n);
        //return uniquePathsDP(m,n);
        
    }
    int uniquePaths3(int m, int n) {
        long long res = 1;
        for (int i = 1; i < n; i++) {
            res = res * (i + m - 1) / i;
        }
        return (int)res;
    }
    int pascalTria(int m, int n) {
        if (m>n) swap(m,n);
        --m,--n;
        
        ///calculate C(n+m,m) = (n+m)!/m!/(n)!
        
        long long res = 1;
        
        //cal (n+m)!/m! = (m+1)*(m+2)*..*(n+m);
        for (int i = 1; i <= n; i++)
            res = res * (i+m) / i;
            
        return (int)res;
    }
        
    int uniquePathsDP(int m, int n) {
        if (m>n) swap(m,n);
        // n is the larger
        
        vector<int> dp(n,1);
        //dp[0]=0; // dummy for the 1st 
        for (int i = 1; i < m; i++) {
            // dp[0] = dp[0]; // unique path to the 1st cell remains the same ( of the next row);
            for (int j = 1; j < n; j++)
                dp[j]+=dp[j-1];
        }
        return dp[n-1];
    }
};

int main() {
    return 0;
}

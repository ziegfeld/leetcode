//============================================================================
// Best Time to Buy and Sell Stock
// 
// Say you have an array for which the ith element is the price of a given 
// stock on day i.
//
// Design an algorithm to find the maximum profit. You may complete at most 
// two transactions.
//
// Note:
// You may not engage in multiple transactions at the same time (ie, you must 
// sell the stock before you buy again).
//
// Complexity:
// O(n)
//============================================================================

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int> & prices) {
        int N = prices.size();
        if (N < 2) return 0;

        int minp = prices[0];
        vector<int> ls(N, 0);
        for (int i = 1; i < N; i++) {
            ls[i] = max(ls[i-1], prices[i]-minp);
            minp = min(minp, prices[i]);
        }

        int maxp = prices[N-1];
        vector<int> rs(N, 0);
        for (int i = N-2; i >= 0; i--) {
            rs[i] = max(rs[i+1], maxp-prices[i]);
            maxp = max(maxp, prices[i]);
        }

        int res = 0;
        for (int i = 0; i < N; i++)
            res = max(res, ls[i]+rs[i]);

        return res;
    }
};


int main() {
    return 0;
}

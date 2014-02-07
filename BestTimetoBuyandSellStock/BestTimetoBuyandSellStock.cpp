//============================================================================
// Best Time to Buy and Sell Stock
//
// Say you have an array for which the ith element is the price of a given
// stock on day i.
//
// If you were only permitted to complete at most one transaction (ie, buy
// one and sell one share of the stock), design an algorithm to find the
// maximum profit.
//
// Complexity:
// O(n)
//============================================================================

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> & prices) {
        int res = 0, minp = INT_MAX;
        for (int p : prices) {
            res = max(res, (p - minp));
            minp = min(minp, p);
        }
        return res;
    }
};

int main() {
    return 0;
}

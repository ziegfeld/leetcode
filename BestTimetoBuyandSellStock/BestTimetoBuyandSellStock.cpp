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
    int maxProfit(vector<int> &prices) {
      return maxProfit_anson627(prices);
    }
    
    // int maxProfit_myWrongAnswer(vector<int> &prices) {
    //     int res = 0, min = INT_MAX;
    //     vector<int>::iterator it = prices.begin();
    //     while (it != prices.end()) {
    //         res = max(res, *it - min);
    //         min = min(min, *it++);
    //     }
    //     return res;
    // }
    

    int maxProfit_anson627(vector<int> &prices) {
        int res = 0, minp = INT_MAX;
        for (int p: prices) {
            res = (res > p - minp)? res : (p - minp);
            minp = (p<minp) ? p : minp;
        }
        return res;
    }
};
int main() {
    return 0;
}

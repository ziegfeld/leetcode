//============================================================================
// There are N children standing in a line. Each child is assigned a rating 
// value.
//
// You are giving candies to these children subjected to the following 
// requirements:
//
// Each child must have at least one candy.
// Children with a higher rating get more candies than their neighbors.
// What is the minimum candies you must give?
//
// Complexity:
// O(n)
//============================================================================

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int candy(vector<int> &ratings) {
        int N = ratings.size();
        vector<int> candies(N, 1);
        for (int i = 1; i < N; i++) if (ratings[i] > ratings[i - 1] && candies[i] <= candies[i - 1]) candies[i] = candies[i - 1] + 1;
        for (int i = N - 2; i >= 0; i--) if (ratings[i] > ratings[i + 1] && candies[i] <= candies[i + 1]) candies[i] = candies[i + 1] + 1;
        int res = 0;
        for (int i = 0; i < N; i++) res += candies[i];
        return res;
    }
};

int main() {
    return 0;
}

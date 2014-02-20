//============================================================================
// Given n non-negative integers a1, a2, ..., an, where each represents a
// point at coordinate (i, ai). n vertical lines are drawn such that the two
// endpoints of line i is at (i, ai) and (i, 0). Find two lines, which
// together with x-axis forms a container, such that the container contains
// the most water.
//
// Note: You may not slant the container.
// 
// Complexity:
// O(n) time
//============================================================================

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
        int i = 0, j = height.size() - 1, res = 0;
        while (i < j) 
            if (height[i] <= height[j]) {
                res = max(res, (j-i) * height[i]);
                do { 
                    ++i; //height decrease, res would not be surpassed, i++
                } while ( i < j && height[i] <= height[i-1]); 

            } else {
                res = max(res, (j-i) * height[j]);
                do { 
                    --j; //height decrease, res would not be surpassed, i++
                } while ( i < j && height[j] <= height[j+1]); 
            }
            
        return res;
    }
};

int main() {
    return 0;
}

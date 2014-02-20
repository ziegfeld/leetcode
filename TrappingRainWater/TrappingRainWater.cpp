//============================================================================
// Trapping Rain Water
// Given n non-negative integers representing an elevation map where the width
// of each bar is 1, compute how much water it is able to trap after raining.
//
// For example,
// Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
//
// Complexity:
// O(n)
//============================================================================

#include <iostream>

using namespace std;

class Solution {
public:
    int trap(int A[], int n) {
        // return trap1(A,n);
        return trap2(A,n);
        
    }
    
    //https://github.com/anson627/leetcode/blob/master/TrappingRainWater/TrappingRainWater.cpp
    int trap2(int A[], int n) {
        int maxi = 0, res = 0;
        for (int i = 1; i < n; i++) if (A[i] > A[maxi]) maxi = i;
        for (int i = 0, h = 0; i < maxi; i++) {
            if (A[i] > h) h = A[i];
            else res += (h - A[i]);
        }
        for (int i = n - 1, h = 0; i > maxi; i--) {
            if (A[i] > h) h = A[i];
            else res += (h - A[i]);
        }
        return res;
    }
    
    // my more complicated solution
    int trap1(int A[], int n) {
        vector<vector<int>> toFill;
        int res = 0;
        //toFill[x][1] colomn is a decreasing sequence. [0] is its index.
        toFill.push_back(vector<int>(2,0));
        toFill[0][1] = A[0];
        for (int x = 1; x<n; x++)
            if (A[x]<=toFill.back()[1]) {
                toFill.push_back(vector<int>(2,x));
                toFill.back()[1] = A[x];
            } else {
                fillUp(toFill,x,A[x],res);
            }
        return res;
    }
    
    void fillUp(vector<vector<int>> & toFill, int xToAdd, int level,  int & res) { // right now we have level>=toFill[kNow][1], xToAdd>toFill[kNow][0]
        
        if (toFill.size() == 1) { 
            // only 2 pieces, no container formed, at least 3 pieces like "L_-" needed.
            toFill.back()[0] = xToAdd;
            toFill.back()[1] = level;
            return; 
        }
        int bottom = toFill.back()[1];
        toFill.pop_back();
        
        //linear search, may be binary search will be better but still needs to enumerate to know the volume of water contained in every places.
        while (!toFill.empty() && toFill.back()[1]<level) {
            res +=(toFill.back()[1] - bottom) * (xToAdd - toFill.back()[0] - 1);
            bottom = toFill.back()[1];
            toFill.pop_back();
        }
        if (!toFill.empty()) { //toFill.back()[1] >= level
            res +=(level - bottom) * (xToAdd - toFill.back()[0] - 1);
            if (toFill.back()[1]!=level) {// this if-condition is an optimization
                toFill.push_back(vector<int>(2,xToAdd));
                toFill.back()[1] = level;
            } else { // if same level, just change the axis of the last piece to the larger x (xToAdd)
                toFill.back()[0] = xToAdd;
            }
        } else { // level is an all time high. toFill emptied.
            toFill.push_back(vector<int>(2,xToAdd));
            toFill.back()[1] = level;
        }
    }
};

int main() {
    Solution sol;

    {
        int p0[] = {0,1,0,2,1,0,1,3,2,1,2,1};
        int p1 = sizeof(p0)/sizeof(p0[0]);
        cout << sol.trap(p0, p1) << endl;
    }
}

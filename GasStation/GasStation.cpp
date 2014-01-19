//============================================================================
// There are N gas stations along a circular route, where the amount of gas 
// at station i is gas[i].
//
// You have a car with an unlimited gas tank and it costs cost[i] of gas to 
// travel from station i to its next station (i+1). You begin the journey 
// with an empty tank at one of the gas stations.
//
// Return the starting gas station's index if you can travel around the 
// circuit once, otherwise return -1.
//
// Note:
// The solution is guaranteed to be unique.
//
// Complexity:
// O(n)
//============================================================================

#include <iostream>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int sumSoFar = 0, sumTotal = 0, res = -1;
        for (int i = 0; i < (int)gas.size(); i++) {
            sumSoFar += (gas[i]-cost[i]);
            sumTotal += (gas[i]-cost[i]);
            if (sumSoFar < 0) {
                sumSoFar = 0;
                res = i;
            }
        }
        return (sumTotal<0)?-1:res+1;
    }
};

int main() {
    return 0;
}

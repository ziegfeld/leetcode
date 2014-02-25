//============================================================================
// Sqrt(x)
// Implement int sqrt(int x).
//
// Compute and return the square root of x.
//
// Complexity:
// Binary Search, log(x)
//============================================================================

#include <iostream>

using namespace std;

class Solution {
public:
    int sqrt(int x) {
        long long l = 0, u = x;
        while (l < u) {
            long long m = l + (u - l + 1) / 2;
            if (m*m > x) u = m - 1;
            else l = m;
        }
        return l;
    }
};

int main() {
    return 0;
}

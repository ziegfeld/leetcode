//============================================================================
// Sqrt(x)
// Implement int sqrt(int x).
//
// Compute and return the square root of x.
//
// Complexity:
// Binary Search, log(x)
// Newton's Method: log(x)
//============================================================================

#include <iostream>
using namespace std;

class Solution {
public:
    class Solution {
    public:
        int sqrt(int x) {
            return sqrt2(x);
        }

        int sqrt1(int x) {
            long long l = 0ll, u = x;
            while (l < u) {
                long long m = l + (u - l + 1) / 2;
                long long p = m*m;
                if (p == x) return (int)m;
                if (p > x) u = m - 1;
                else l = m;
            }
            return (int)l;
        }

        int sqrt2(int x) {
            double r0 = 0, r1 = x / 2.0;
            while (abs(r1 - r0) > 0.01) {
                r0 = r1;
                r1 = (r0 + x / r0) / 2.0;
            }
            return (int)r1;
        }
    };
};

int main() {
    return 0;
}

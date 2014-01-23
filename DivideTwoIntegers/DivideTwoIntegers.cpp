//============================================================================
// Divide two integers without using multiplication, division and mod operator.
//
// Complexity:
// O(1) time
//============================================================================

class Solution {
public:
    int divide(int dividend, int divisor) {
        int sn = 1;
        long long dd = dividend, dr = divisor;
        if (dd < 0) dd = -dd, sn = -sn;
        if (dr < 0) dr = -dr, sn = -sn;
        long long res = 0;
        while (dd >= dr) {
            long long sf = 0, tmp = dr;
            while ((tmp<<1) <= dd) tmp <<= 1, sf++;
            dd -= tmp;
            res |= (1<<sf);
        }
        return sn*res;
    }
};

int main() {
    return 0;
}

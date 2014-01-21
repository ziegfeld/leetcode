//============================================================================
// Pow(x, n)
// Implement pow(x, n).
//============================================================================

class Solution {
public:
    double pow(double x, int n) {
        int sn = 1;
        if (n < 0) sn = -sn, n = -n;
        double res = pow1(x, n);
        if (sn < 0) return 1.0/res;
        return res;
    }

    double pow1(double x, int n) {
        double tmp = x, res = 1.0;
        for (int t = n; t > 0; t /= 2) {
            if(t % 2 == 1) res *= tmp;
            tmp = tmp * tmp;
        }

        return res;
    }

    double pow2(double x, int n) {
        if (n == 0) return 1.0;
        double t = pow2(x, n/2); 
        if (n%2 == 0) return t*t;
        return x*t*t;
    }

    double pow3(double x, int n) {
        if (n == 0) return 1.0;
        if (n%2) return x*pow(x, n-1);
        double t = pow(x, n/2);
        return t*t;
    }
};

int main() {
    return 0;
}

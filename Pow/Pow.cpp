//============================================================================
// Pow(x, n)
// Implement pow(x, n).
//============================================================================

class Solution {
public:
    double pow(double x, int n) {
        int sn = 1;
        if (n < 0) n = -n, sn = -sn;
        double res = pow1(x, n);
        return (sn > 0) ? res : 1.0 / res;
    }

    double pow1(double x, int n) {
        double res = 1.0, t = x;
        for (; n > 0; n /= 2) {
            if (n % 2) res *= t;
            t *= t;
        }
        return res;
    }

    double pow2(double x, int n) {
        if (n == 0) return 1.0;
        double t = pow2(x, n / 2);
        if (n % 2 == 0) return t*t;
        return x*t*t;
    }

    double pow3(double x, int n) {
        if (n == 0) return 1.0;
        if (n % 2) return x*pow(x, n - 1);
        double t = pow(x, n / 2);
        return t*t;
    }
};

int main() {
    return 0;
}

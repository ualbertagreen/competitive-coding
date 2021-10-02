class Solution {
public:
    double fastExp(double x, long n) { // 16 * 4 * 2 == 2^7
        if (n == 0) return 1.0;
        if (n & 1) {
            return fastExp(x * x, n/2) * x; // x = 2.0, n = 3 | x = 4.0, n = 1 | x = 16.0, n = 0
        }
        else return fastExp(x * x, n/2);
    }
    
    double myPow(double x, int n) { //x = 2.0000, n = 7
        if (n < 0) {
            return 1.0 / fastExp(x, -1L * n);
        }
        else {
            return fastExp(x, n);
        }
    }
};
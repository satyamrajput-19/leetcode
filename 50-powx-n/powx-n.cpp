class Solution {
public:
    double power(double x, long long n) {
        if (n == 0) {
            return 1;
        }
        if (n < 0) {
            return 1 / power(x, -n);
        }
        
        double temp = power(x, n / 2);
        
        if (n % 2 == 0) {
            return temp * temp;
        } else {
            return temp * temp * x;
        }
    }

    double myPow(double x, int n) {
        return power(x, (long long)n);
    }
};
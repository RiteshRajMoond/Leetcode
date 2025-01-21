class Solution {
public:
    double myPow(double x, long n) {
        if(n < 0) {
            x = 1/x;
            n = -n;
        }
        return f(x, n);
    }
private:
    double f(double x, int n) {
        if(n == 0) return 1;

        double p = f(x, n/2);
        if(n&1) return p*p*x;
        else return p*p;
    }
};
class Solution {
public:

    double solve(double x, long n){
        if(n==0){
            return 1;
        }
        if(n < 0){
            return 1 / solve(x, -n);
        }
        double half = solve(x, n/2);
        if(n%2 == 0){
            return half*half;
        }else{
            return half*half*x;
        }
    }
    double myPow(double x, int n) {
        return solve(x, long(n));
    }
};
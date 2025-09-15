class Solution {
public:
    const int mod = 1e9 + 7;
    long long solve(long long base, long long expoential){
        if(expoential == 0){
            return 1;
        }
        long long half = solve(base, expoential/2);
        long long result = (half*half) % mod;

        if(expoential % 2 == 1){
            result = (result *base) % mod;
        }
        return result;
    }
    int countGoodNumbers(long long n) {
        long even = n/2 + n % 2;
        long  odd = n/2;

        long evenpart = solve(5, even);
        long oddpart = solve(4, odd);

        return (evenpart * oddpart) % mod;
    }
};





































































































































































































class Solution {
public:
    int binarySearch(int x){
        if(x <= 1) return x;
        int S = 0, e = x-1;
        long long ans = 0;
        while(S <=e){
            long long mid = S + (e-S)/2;
            long long Squre = mid*mid;
            if(Squre == x){
                return mid;
            }else if(Squre < x){
                ans = mid;
                S = mid+1;
            }else{
                e = mid-1;
            }
        }
        return ans;
    }
    int mySqrt(int x) {
        return binarySearch(x);
    }
};
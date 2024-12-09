class Solution {
public:
    bool judgeSquareSum(int c) {
        if(c < 0){
            return false;
        }
        long long low = 0, high = sqrt(c);

        while(low <=high){
            int mid = (low+high)/2;
            long long sum = low*low+high*high;
            if(sum == c){
                return true;
            }else if(sum < c){
                low++;
            }else{
                high--;
            }
        }
        return false;
    }
};
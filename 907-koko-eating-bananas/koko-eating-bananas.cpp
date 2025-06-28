class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = *max_element(piles.begin(), piles.end());
        int result = high;

        while(low <= high){
            int mid = low + (high - low)/2;
            long long  totalhourS = 0;
            for(int pile : piles){
                totalhourS += (pile + mid - 1)/mid;
            }
            if(totalhourS <= h){
                result = mid;
                high  = mid-1;
            }else{
                low = mid+1;
            }
        }
        return result;
    }
};
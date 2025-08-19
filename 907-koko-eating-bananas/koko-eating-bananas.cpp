class Solution {
public:
    bool isPossilbe(vector<int>&piles, int mid, int h){
        int actualhourS = 0;
        for(int & x: piles){

            actualhourS += x / mid;
            if(x% mid != 0){
                actualhourS++;
            }
        }
        if(actualhourS <= h){
            return true;
        }
        return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int l = 1, r = *max_element(piles.begin(), piles.end());

        int reSult = r;
        while(l < r){
            int mid = l + (r-l)/2;
            if(isPossilbe(piles, mid, h)){
                reSult = mid;

                r = mid;
            }else{
                l = mid+1;
            }
        }
        return reSult;
    }
};
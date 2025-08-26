class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        int count = 1;

        int laSthigh = pairs[0][1];
        for(int i = 1; i<pairs.size(); i++){
            if(pairs[i][0] > laSthigh){
                count++;
                laSthigh = pairs[i][1];
            }else{
                laSthigh = min(laSthigh, pairs[i][1]);
            }
        }
        return count;
    }
};




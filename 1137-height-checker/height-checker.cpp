class Solution {
public:
    int heightChecker(vector<int>& heights) {
        
        int n = heights.size();
        int count =0;
        vector<int>m = heights;

        sort(m.begin(), m.end());
        
        for(int i =0; i<n; i++){
                if(heights[i] != m[i]){
                    count++;
                
            }
        }
        return count;
    }
};
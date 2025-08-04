class Solution {
public:
    int totalFruit(vector<int>& s) {
        int n = s.size();
        int l = 0, r = 0, maxlen = 0;

        unordered_map<int,int>freq;
        while(r < n){
            freq[s[r]]++;
            while(freq.size() > 2){
                freq[s[l]]--;
                if(freq[s[l]] == 0){
                    freq.erase(s[l]);
                }
                l++;
            }
            maxlen = max(maxlen, r-l+1);
            r++;
        }
        return maxlen;
    }  
};
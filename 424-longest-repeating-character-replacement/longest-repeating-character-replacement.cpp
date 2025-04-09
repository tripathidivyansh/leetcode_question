class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int l = 0, r = 0, count = 0, maxlen = 0;
        vector<int>freq(256, 0);

        while(r < n){
            freq[s[r]]++;
            count = max(count, freq[s[r]]);

            while((r-l+1) - count > k){
                freq[s[l]]--;
                l++;
            }
            maxlen = max(maxlen, r-l+1);
            r++;
        }
        return maxlen;
    }
};
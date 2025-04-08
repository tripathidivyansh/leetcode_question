class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int l = 0, r = 0, count = 0, maxlen = 0;

        vector<int>freq(26, 0);
        while(r < s.size()){
            freq[s[r] - 'A']++;
            count = max(count, freq[s[r] - 'A']);

            while((r-l+1) - count > k){
                freq[s[l] - 'A']--;
                l++;
            }
            maxlen = max(maxlen, r-l+1);
            r++;
        }
        return maxlen;
        
    }
};
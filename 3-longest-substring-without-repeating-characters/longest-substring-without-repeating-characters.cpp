class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int hash[256] = {0};
        memset(hash, -1, sizeof(hash));
        int l = 0, r = 0;
        int maxlen = 0;
        while(r < n) {
            if(hash[s[r]] >= l) {
                l = hash[s[r]] + 1;
            }
            int len = r - l + 1;
            maxlen = max(len, maxlen);
            hash[s[r]] = r;
            r++;
        }
        return maxlen;
    }
};


// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         int n = s.size();
//         int maxlen = 0;
//         for(int i = 0; i<n; i++){
//             int hash[256] = {0};
//             for(int j = i; j<n; j++){
//                 if(hash[s[j]] == 1) break;
//                 int len = j-i+1;
//                 maxlen = max(len, maxlen);
//                 hash[s[j]] = 1;
//             }
//         }
//         return maxlen;
//     }
// };
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        // if(n > m) return false;
        // sort(s1.begin(), s1.end());
        // for(int i = 0; i<=m-n; i++){
        //     string substr = s2.substr(i, n);
        //     sort(substr.begin(), substr.end());
        //     if(s1 == substr)return true;
        // }
        // return false;
        if(n > m) return false;
        vector<int> S1_freq(26, 0);
        vector<int> S2_freq(26, 0);
        
        for(auto & ch : s1){
            S1_freq[ch-'a']++;
        }
        int i = 0, j = 0;
        while(j < m){
            S2_freq[s2[j] - 'a']++;
            if(j-i+1 > n){
                S2_freq[s2[i] - 'a']--;
                i++;
            }
            if(S1_freq == S2_freq) return true;
            j++;
        }
        return false;
    }
};
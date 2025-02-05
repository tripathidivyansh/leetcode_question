class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.size();
        if(s1==s2){
            return true;
        }
        int s1freq[26] = {0};
        int s2freq[26] = {0};

        int diff = 0;
        for(int i  = 0; i<n; i++){
            char s1char = s1[i];
            char s2char = s2[i];

            if(s1char != s2char){
                diff++;
                if(diff>2){
                    return false;
                }
                s1freq[s1char-'a']++;
                s2freq[s2char-'a']++;
            }
        }
        for(int i = 0; i<26; i++){
            if(s1freq[i] != s2freq[i]){
                return false;
            }
        }
        return true;
    }
};
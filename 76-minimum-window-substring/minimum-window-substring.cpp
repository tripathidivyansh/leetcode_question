class Solution {
public:

    string solve(string& s, string& t){
        int n = s.size();
        int m = t.size();

        int hash[256] = {0};
        for(char c : t){
            hash[c]++;
        }
        int l = 0, r = 0, count = 0, minlen = INT_MAX, sindex = -1;

        while(r < s.size()){
            if(hash[s[r]] > 0){
                count++;
            }
            hash[s[r]]--;

            while(count == m){
                if(r-l+1 < minlen){
                    minlen = r-l+1;
                    sindex = l;
                }
                hash[s[l]]++;
                if(hash[s[l]] > 0){
                    count--;
                }
                l++;
            }
            r++;
        }
        if(sindex == -1){
            return "";
        }
        return s.substr(sindex, minlen);
    }
    string minWindow(string s, string t) {
        return solve(s, t);
    }
};
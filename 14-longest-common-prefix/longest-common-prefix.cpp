class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        string prefix = "";

        string first = strs[0];
        string last = strs[strs.size()- 1];
        for(int i = 0; i<first.size(); i++){
            if(first[i] != last[i]) break;
            prefix += first[i];
        }


        return prefix;
    }
};
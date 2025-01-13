class Solution {
public:
    int minimumLength(string s) {
        // unordered_map<char,int>mp;
        // int ans = 0;
        // for(int i = 0; i<s.size(); i++){
        //     mp[s[i]]++;
        // }
        // for(auto malik:mp){
        //     int count = malik.second;
        //     while(count >= 3){
        //         count -= 2;
        //     }
        //     ans += count;
        // }
        // return ans;













        int ans = 0;
        unordered_map<char,int>mp;
        for(int i = 0; i<s.size(); i++){
            mp[s[i]]++;
        }
        for(auto malik : mp){
            int count = malik.second;
            while(count >= 3){
                count -= 2;
            }
            ans += count;
        }
        return ans;
    }
};
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int n = ransomNote.size();
        int m = magazine.size();
        if(n > m){
            return false;
        }
        unordered_map<char, int> mp;
        for(int i = 0; i<m; i++){
            mp[magazine[i]]++;
        }
        for(char c : ransomNote){
            if(mp[c] > 0){
                mp[c]--;
            }else{
                return false;
            }
        }
        return true;
    }
};
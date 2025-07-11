class Solution {
public:
    bool isPalindrome(string &s, int i, int j){
        while(i<j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    void solve(int index, string& s, vector<vector<string>>&result, vector<string>&path){
        if(index >= s.size()){
            result.push_back(path);
            return;
        }
        for(int i = index; i<s.size(); i++){
            if(isPalindrome(s, index, i)){
                path.push_back(s.substr(index, i - index + 1));
                solve(i+1, s, result, path);
                path.pop_back();
            }
        }

    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>result;
        vector<string>path;

        solve(0, s, result, path);
        return result;
    }
};
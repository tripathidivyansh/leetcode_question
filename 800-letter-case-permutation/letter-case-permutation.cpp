class Solution {
public:

    void solve(int index, string& path, vector<string>&ans, string &s){
        if(index >= s.size()){

            ans.push_back(path);
            return;
        }
        path.push_back(s[index]);
        solve(index + 1, path, ans, s);
        path.pop_back(); 

        if(isalpha(s[index])) {
            char ch;
            if(isupper(s[index])) {

                ch = tolower(s[index]);
            } else {
                ch = toupper(s[index]);
            }
            path.push_back(ch);
            solve(index + 1, path, ans, s);
            path.pop_back();  
        }
    }
    vector<string> letterCasePermutation(string s) {
        string path;
        vector<string>ans;

        solve(0, path, ans, s);
        return ans;
    }
};
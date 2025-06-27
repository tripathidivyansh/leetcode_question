class Solution {
public:

    void solve(int n, vector<string>&ans, string temp){
        if(temp.size() >= n){

            ans.push_back(temp);
            return;
        }
        solve(n, ans, temp + "1");
        if(temp.empty() || temp.back() == '1'){
            solve(n, ans, temp + "0");
        }
    }
    vector<string> validStrings(int n) {
        vector<string>ans;
        string temp = "";

        solve(n, ans, temp);
        return ans;
    }
};
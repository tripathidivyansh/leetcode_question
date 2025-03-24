class Solution {
public:

    void solve(vector<string>&ans, string temp, int n){
        if(temp.size() == n){
            ans.push_back(temp);
            return;
        }
        solve(ans, temp + "1", n);
        if(temp.empty() || temp.back() == '1'){
            solve(ans, temp+"0", n);
        }
    }
    vector<string> validStrings(int n) {
        vector<string>ans;
        string temp = "";
        solve(ans, temp, n);
        return ans;
    }
};
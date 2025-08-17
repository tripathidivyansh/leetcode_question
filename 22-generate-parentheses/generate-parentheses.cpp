class Solution {
public:

    void solve(int n, vector<string>&ans, string temp, int open, int close){
        if(temp.size() == 2*n){

            ans.push_back(temp);
            return;
        }
        if(open < n){
            solve(n, ans, temp + "(", open+ 1, close);   
        }
        if(close < open){
            solve(n, ans, temp + ")" , open , close+1);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string temp = "";

        solve(n, ans, temp, 0, 0);
        return ans;
    }
};











































































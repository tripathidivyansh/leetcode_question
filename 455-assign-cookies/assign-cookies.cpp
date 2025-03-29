class Solution {
public:

    int solve(int i, int j, vector<int>&g, vector<int>&s){
        if(i >=g.size() || j>= s.size()){
            return 0;
        }
        if(g[i] <= s[j]){
            return 1 + solve(i+1, j+1, g, s);
        }else{
            return solve(i, j+1, g, s);
        }
    }
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = g.size();
        int m = s.size();

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        return solve(0, 0, g, s);
    }
};
class Solution {
public:
    void findCombination(int start, int n, int k, vector<vector<int>>& ans, vector<int>& ds) {
        if (ds.size() == k) {
            ans.push_back(ds);
            return;
        }
        for (int i = start; i <= n; i++) {
            ds.push_back(i);
            findCombination(i + 1, n, k, ans, ds);
            ds.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> ds;
        findCombination(1, n, k, ans, ds);
        return ans;
    }
};

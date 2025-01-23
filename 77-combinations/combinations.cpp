class Solution {
public:
    void func(int start, int n, int k, vector<int>& subset, vector<vector<int>>& result) {
        if (subset.size() == k) {
            result.push_back(subset);
            return;
        }
        for (int i = start; i <= n; i++) {
            subset.push_back(i);
            func(i + 1, n, k, subset, result);
            subset.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> subset;
        vector<vector<int>> result;
        func(1, n, k, subset, result);
        return result;
    }
};

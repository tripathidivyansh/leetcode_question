class Solution {
public:
    static bool cmp(pair<double, pair<int,int>> &a, pair<double, pair<int,int>> &b) {
        return a.first < b.first;
    }

    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<pair<double, pair<int,int>>> ans;
        int n = arr.size();
        for (int i = 0; i < n; i++) {

            for (int j = i + 1; j < n; j++) {
                ans.push_back({(double)arr[i] / arr[j], {arr[i], arr[j]}});
            }
        }
        sort(ans.begin(), ans.end(), cmp);

        return {ans[k-1].second.first, ans[k-1].second.second};
    }
};


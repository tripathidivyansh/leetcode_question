class Solution {
public:
    int findLucky(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int>mp;

        for(int i = 0; i<arr.size(); i++){
            mp[arr[i]]++;
        }
        int ans = -1;
        for(auto &malik : mp){
            if(malik.second == malik.first){
                ans = max(ans, malik.first);
            }
        }
        return ans;
    }
};
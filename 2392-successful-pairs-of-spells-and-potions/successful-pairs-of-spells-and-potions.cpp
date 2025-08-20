class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        int n = potions.size();

        vector<int>ans;
        for(int &splle : spells){
            long long need = (success + splle -1) /splle;
            int idx = lower_bound(potions.begin(), potions.end(), need) - potions.begin();
            ans.push_back(n - idx);
        }

        return ans;
    }
};






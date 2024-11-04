class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();
        if(n % k != 0){
            return false;
        }
        map<int, int>mp;
        for(int i = 0; i<n; i++){
            mp[nums[i]]++;
        }
        for(map<int, int>::iterator it = mp.begin(); it != mp.end(); it++){
            int startCard = it->first;
            int count = it->second;

            if(count > 0){
                for(int i = 1; i<k; i++){
                    int nextCard = startCard + i;
                    mp[nextCard] -= count;
                    if(mp[nextCard] < 0){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
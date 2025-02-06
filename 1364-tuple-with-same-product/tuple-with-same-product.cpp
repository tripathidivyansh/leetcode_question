class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        
       int n = nums.size();
       unordered_map<int,int>mp;
       int count = 0;
       for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                int product = nums[i] * nums[j];
                mp[product]++;
            }
        }
        for(auto it: mp){
            int freq = it.second;
            if(freq>1){
                count+= (freq*(freq-1))/2;
            }
        }
        return count*8;
    }
};
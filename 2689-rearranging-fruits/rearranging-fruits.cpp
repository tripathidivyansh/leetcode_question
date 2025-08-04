class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int,int>mp;
        int minEle = INT_MAX; 
        for(int &x : basket1){
            mp[x]++;
            minEle = min(minEle, x);
        }
        for(int &x : basket2){
            mp[x]--;
            minEle = min(minEle, x);
        }
        vector<int>finallist;
        for(auto &it: mp){
            int coSt = it.first;
            int count = it.second;
            if(count == 0){
                continue;
            }
            if(count % 2 != 0) return -1;
            for(int c = 1; c <= abs(count/2); c++){
                finallist.push_back(coSt);
            }
        }
        
        sort(begin(finallist), end(finallist));
        long long reSult = 0;
        for(int i = 0; i<finallist.size()/2; i++){
            reSult += min(finallist[i], minEle*2);
        }
        return reSult;
    }
};
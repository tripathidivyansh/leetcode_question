class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        int n = arr.size();
        unordered_set<int>result;
        unordered_set<int>previouS;
        for(int num : arr){
            unordered_set<int>curr;
            curr.insert(num);
            for(int p  : previouS){
                curr.insert(p | num);
            }
            previouS = curr;
            for(int x : curr) result.insert(x);
        }
        return result.size();

    }
};
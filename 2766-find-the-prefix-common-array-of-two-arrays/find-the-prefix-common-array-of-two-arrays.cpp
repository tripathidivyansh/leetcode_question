class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        int m = B.size();
        vector<int>ans;
        unordered_map<int,int>mp;   
        int commonCount = 0;
        for(int i  = 0; i<n; i++){
            mp[A[i]]++;
            if(mp[A[i]] == 2){
                commonCount++;
            }
            mp[B[i]]++;
            if(mp[B[i]] == 2){
                commonCount++;
            }
            ans.push_back(commonCount);
        }
       return ans;
    }
};
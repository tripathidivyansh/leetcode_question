class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> res;
        int cur = 1; 
        
        for (int num : target) {
            while (cur < num) {
                res.push_back("Push");
                res.push_back("Pop");
                cur++;
            }
            res.push_back("Push");
            cur++;
        }
        
        return res;
    }
};



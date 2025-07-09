class Solution {
public:
    void solve(int curr, int n, vector<int>&result){
        if(curr > n){
            return;
        }
        result.push_back(curr);
        for(int append = 0; append <= 9; append++){
            int newCurr = curr*10 + append;
            if(newCurr > n){
                return;
            }
            solve(newCurr, n, result);
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int>result;
        for(int start = 1; start<= 9; start++){

            solve(start, n, result);
        }
        return result;
    }
};
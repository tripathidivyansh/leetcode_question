class Solution {
public:

    void solve(int index, vector<int>&cookies, vector<int>&children, int &result, int k){
        if(index >= cookies.size()){

            int maxcookieS = *max_element(children.begin(), children.end()); 
            result = min(result, maxcookieS);
            return;
        }
        for(int i = 0; i<k; i++){
            children[i] += cookies[index];
            if(children[i] <= result){
                solve(index+1, cookies, children, result, k);
            }
            children[i] -= cookies[index];

            if(children[i] == 0) break;
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        int n = cookies.size();
        vector<int>children(k, 0);

        int result = INT_MAX;
        solve(0, cookies, children, result, k);
        return result;
    }
};
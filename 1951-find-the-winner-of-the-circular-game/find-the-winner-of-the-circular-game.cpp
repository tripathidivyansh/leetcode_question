class Solution {
public:
    // int solve(int n, int k) {
    //     if(n == 1) {
    //         return 0;
    //     }

    //     // return (solve(n - 1, k) + k) % n;
    //     return (solve(n-1, k)+ k)%n;
    // }
    
    int findTheWinner(int n, int k) {
        // return solve(n, k)+1;
        vector<int>arr;
        for(int i = 1; i<=n; i++){
            arr.push_back(i);
        }
        int i = 0;
        while(arr.size() > 1){
            int index = (i+k - 1) % arr.size();
            arr.erase(arr.begin() + index);
            i = index;
        }
        return arr[0];
    }
};
// class Solution {
// public:
//     int kthSmallest(vector<vector<int>>& matrix, int k) {
//         vector<int>ans;
//         int n = matrix.size();
//         for(int i =0; i<n; i++){
//             for(int j = 0; j<n; j++){
//                 ans.push_back(matrix[i][j]);
//             }
//         }
//         sort(ans.begin(), ans.end());
//         return ans[k-1];
//     }
// };


class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int>maxHeap;
        int n = matrix.size();
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                maxHeap.push(matrix[i][j]);
                if(maxHeap.size() > k){
                    maxHeap.pop();
                }
            }
        }
        return maxHeap.top();
    }
};
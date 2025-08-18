class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // for(int i = 0; i<matrix.size(); i++){
        //     for(int j = 0; j<matrix[0].size(); j++){
        //         if(matrix[i][j] == target){
        //             return true;
        //         }
        //     }
        // }
        // return false;
        // int i = 0, j = matrix[0].size()-1;
        // while(i < matrix.size() && j >= 0){
        //     if(matrix[i][j] == target){
        //         return true;
        //     }else if(matrix[i][j] < target){
        //         i++;
        //     }else{
        //         j--;
        //     }
        // }
        // return false;
        int n = matrix.size(), m = matrix[0].size();
        int low = 0, high = n * m - 1;
        for (int i = 0; i < n; i++) {
            
            if (target < matrix[i][0] || target > matrix[i][m - 1]) {
                continue;
            }
            
            int low = 0, high = m - 1;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (matrix[i][mid] == target) return true;
                if (matrix[i][mid] < target) low = mid + 1;
                else high = mid - 1;
            }
        }
        return false;
    }
};














class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        // int i = 0, j = m-1;
        // while(i< n && j >= 0){
        //     if(matrix[i][j] == target){
        //         return true;
        //     }else if(matrix[i][j] < target){
        //         i++;
        //     }else{
        //         j--;
        //     }
        // }

        // return false;
        int low = 0, high = n*m - 1;
        while(low <= high){
            int mid = low + (high-low)/2;

            int row = mid/m;
            int coln = mid %m;
            if(matrix[row][coln] == target) return true;
            else if(matrix[row][coln] < target) low = mid+1;
            else high = mid-1;
        }
        return false;
    }
};


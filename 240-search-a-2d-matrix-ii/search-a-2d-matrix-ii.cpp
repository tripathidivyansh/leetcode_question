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
        int i = 0, j = matrix[0].size()-1;
        while(i < matrix.size() && j >= 0){
            if(matrix[i][j] == target){
                return true;
            }else if(matrix[i][j] < target){
                i++;
            }else{
                j--;
            }
        }
        return false;
    }
};









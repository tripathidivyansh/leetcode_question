class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        for(int r=0; r<4; r++){
            if(mat == target){
                return true;
            }
            for(int i = 0; i<n; i++){
                for(int j = i; j<n; j++){
                    swap(mat[i][j], mat[j][i]);
                }
            }
            for(int i = 0; i<n; i++){
                reverse(mat[i].begin(), mat[i].end());
            }
        }
        return false;
    }
};
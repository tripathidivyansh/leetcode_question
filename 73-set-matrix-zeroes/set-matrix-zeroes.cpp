class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(matrix[i][j] == 0){
                    for(int k = 0; k<n; k++){
                        if(matrix[k][j] == 0){
                            continue;
                        }
                        matrix[k][j] = -999;
                    }
                    for(int a = 0; a<m; a++){
                        if(matrix[i][a] == 0){
                            continue;
                        }
                        matrix[i][a] = -999;
                    }
                }
            }
        }
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(matrix[i][j] == -999){
                    matrix[i][j] = 0;
                }
            }
        }

























    }
};


// class Solution {
// public:
//     void setZeroes(vector<vector<int>>& matrix) {
//         int n = matrix.size();
//         int m = matrix[0].size();

//         for(int i = 0; i<n; i++){
//             for(int j = 0; j<m; j++){
//                 if(matrix[i][j] == 0){
//                     for(int k = 0; k<n; k++){
//                         if(matrix[k][j] == 0){
//                             continue;
//                         }
//                         matrix[k][j] = -999;
//                     }
//                     for(int a = 0; a<m; a++){
//                         if(matrix[i][a] == 0){
//                             continue;
//                         }
//                         matrix[i][a] = -999;
//                     }
//                 }
//             }
//         }
//         for(int i = 0; i<n; i++){
//             for(int j = 0; j<m; j++){
//                 if(matrix[i][j] == -999){
//                     matrix[i][j] = 0;
//                 }
//             }
//         }
//     }
// };
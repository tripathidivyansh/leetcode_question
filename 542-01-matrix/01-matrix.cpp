class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> viS(n, vector<int>(m, 0));
        vector<vector<int>> diSt(n, vector<int>(m, 0));
        queue<pair<pair<int, int>, int>> q;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(mat[i][j] == 0) {
                    q.push({{i, j}, 0});
                    viS[i][j] = 1;
                }
            }
        }
        vector<int> delrow = {-1, 0, 1, 0};
        vector<int> delcol = {0, 1, 0, -1};
        while(!q.empty()) {
            int row = q.front().first.first;

            int col = q.front().first.second;
            int step = q.front().second;
            q.pop();
            diSt[row][col] = step;
            for(int i = 0; i < 4; i++) {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && viS[nrow][ncol] == 0) {
                    viS[nrow][ncol] = 1;
                    q.push({{nrow, ncol}, step + 1});
                }
            }
        }

        return diSt;
    }
};

















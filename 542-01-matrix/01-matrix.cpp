class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<bool>>visited(n, vector<bool>(m, false));
        queue<pair<int,int>>q;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(mat[i][j] == 0){
                    q.push({i, j});
                    visited[i][j] = true;
                }
            }
        }
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, -1, 0, 1};
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int i = 0; i<4; i++){
                int di = x + dx[i];
                int dj = y + dy[i];
                if(di >= 0 && dj >= 0 && di < n && dj < m && !visited[di][dj]){
                    q.push({di, dj});
                    visited[di][dj] = true;
                    mat[di][dj] = mat[x][y] + 1;
                }
            }
        }
        return mat;
    }
};
class Solution {
public:

    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int time = 0, freSh = 0;
        queue<pair<int,int>>q;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                }else if(grid[i][j] == 1){
                    freSh++;
                }
            }
        }
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, -1, 0, 1};
        while(freSh > 0 && !q.empty()){
            int length = q.size();
            for(int i = 0; i<length; i++){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                for(int i = 0; i<4; i++){
                    int di = x + dx[i];
                    int dj = y + dy[i];
                    if(di >= 0 && dj >= 0 && di < n && dj < m && grid[di][dj] == 1){
                        grid[di][dj] = 2;
                        q.push({di, dj});
                        freSh--;
                    }
                }
            }
            time++;
        }
        return freSh == 0 ? time : -1;
    }
};
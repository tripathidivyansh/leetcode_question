class Solution {
public:
    void Solve(int i, int j, vector<vector<char>>&grid){
        int n = grid.size();
        int m = grid[0].size();

        if(i < 0 || j < 0 || i>= n || j>= m || grid[i][j] == '0') return;
        grid[i][j] = '0';
        Solve(i, j+1, grid);
        Solve(i, j-1, grid);

        Solve(i+1, j, grid);
        Solve(i-1, j, grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int count = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == '1'){
                    Solve(i, j, grid);
                    count++;
                }
            }
        }
        return count;
    }
};
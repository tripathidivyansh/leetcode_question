class Solution {
public:

    int  solve(vector<vector<int>>&grid, int i, int j, int n, int m){
        if(i < 0 || j < 0 || i>= n || j>= m || grid[i][j] != 1){
            return 0;
        }
        int ans = 1;
        grid[i][j] = 0;
        ans += solve(grid, i+1, j, n, m);
        ans += solve(grid, i-1, j, n, m);
        ans += solve(grid, i, j+1, n, m);
        ans += solve(grid, i, j-1, n, m);

        return ans;
    } 
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int count = 0;
        int maxarea = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 1){
                    int ans = solve(grid, i, j, n, m);
                    maxarea = max(maxarea, ans);
                }
            }
        }
        return maxarea;
    }
};
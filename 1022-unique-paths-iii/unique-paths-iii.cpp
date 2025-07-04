class Solution {
public:
    int count = 0;
    int totalSteps = 0;

    bool solve(vector<vector<int>>& grid, int i, int j, int steps, vector<vector<bool>>& visited) {
        int n = grid.size();
        int m = grid[0].size();

    
        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == -1 || visited[i][j]) {
            return false;
        }

        if (grid[i][j] == 2) {
            if (steps == totalSteps) {
                count++;
            }
            return false;
        }

        visited[i][j] = true;

        solve(grid, i + 1, j, steps + 1, visited);
        solve(grid, i - 1, j, steps + 1, visited);
        solve(grid, i, j + 1, steps + 1, visited);
        solve(grid, i, j - 1, steps + 1, visited);

        visited[i][j] = false;

        return false;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int startX, startY;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] != -1) {
                    totalSteps++;
                }
                if (grid[i][j] == 1) {
                    startX = i;
                    startY = j;
                }
            }
        }
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        solve(grid, startX, startY, 1, visited); 
        return count;
    }
};

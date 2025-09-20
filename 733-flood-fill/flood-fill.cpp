class Solution {
public:
    void dfs(vector<vector<int>>& image, int i, int j, int newColor, int oldColor) {
        int n = image.size();
        int m = image[0].size();
        if (i < 0 || j < 0 || i >= n || j >= m || image[i][j] != oldColor) return;
        image[i][j] = newColor;
        dfs(image, i+1, j, newColor, oldColor);
        dfs(image, i-1, j, newColor, oldColor);
        dfs(image, i, j+1, newColor, oldColor);

        dfs(image, i, j-1, newColor, oldColor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldColor = image[sr][sc];
        if(oldColor == color) return image; 
        dfs(image, sr, sc, color, oldColor);
        return image;
    }
};


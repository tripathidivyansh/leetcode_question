class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int n = image.size();
        
        for (auto &row : image) {
            int i = 0, j = row.size() - 1;
            while (i <= j) {
        
                int temp = row[i] ^ 1;
                row[i] = row[j] ^ 1;
                row[j] = temp;
                i++;
                j--;
            }
        }
        
        return image;
    }
};


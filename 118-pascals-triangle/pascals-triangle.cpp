class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>traingle;
        for(int i = 0; i<numRows; i++){

            vector<int>row(i+1, 1);
            for(int j = 1; j<i; j++){
                row[j] = traingle[i-1][j-1] + traingle[i-1][j]; 
            }
            traingle.push_back(row);
        }
        return traingle;
    }
};
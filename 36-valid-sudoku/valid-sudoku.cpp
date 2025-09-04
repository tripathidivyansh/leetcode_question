class Solution {
public:
    bool iSvalid(vector<vector<char>>&board, int S, int r, int u, int v){
        set<char>St;
        for(int i = S; i <=r; i++){
            for(int j = u; j<=v; j++){
                if(board[i][j] == '.') continue;
                if(St.find(board[i][j]) != St.end()) return false;
                St.insert(board[i][j]);
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int row = 0; row < 9; row++){
            set<char>St;

            for(int coln = 0; coln < 9; coln++){
                if(board[row][coln] == '.') continue;
                if(St.find(board[row][coln]) != St.end()) return false;
                St.insert(board[row][coln]);
            }
        }
        for(int coln = 0; coln < 9; coln++){
            set<char>St;
            for(int row = 0; row < 9; row++){
                if(board[row][coln] == '.') continue;
                if(St.find(board[row][coln]) != St.end()) return false;
                St.insert(board[row][coln]);
            }
        }
        for(int S = 0; S < 9; S += 3){
            int r = S+2;
            for(int u = 0; u<9; u += 3){
                int v = u+2;
                if(!iSvalid(board, S, r, u, v)) return false;
            }
        }
        return true;
    }
};



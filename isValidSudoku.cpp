class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int i,j;
        for(i=0;i<9;i++){
            bool row[9] = {false};
            bool col[9] = {false};
            for(j=0;j<9;j++){
                if(board[i][j] != '.'){
                    int num = board[i][j] -'1';
                    if(row[num]) return false;
                    row[num] = true;
                }
                if (board[j][i] != '.') {
                    int num = board[j][i] - '1';
                    if (col[num]) return false;
                    col[num] = true;
                }
            }
        }
        for (int blockRow = 0; blockRow < 3; blockRow++) {
            for (int blockCol = 0; blockCol < 3; blockCol++) {
                bool box[9] = {false};
                for ( i = 0; i < 3; i++) {
                    for ( j = 0; j < 3; j++) {
                        int row = blockRow * 3 + i;
                        int col = blockCol * 3 + j;
                        if (board[row][col] != '.') {
                            int num = board[row][col] - '1';
                            if (box[num]) return false;
                            box[num] = true;
                        }
                    }
                }
            }
        }
        return true;
    }
};
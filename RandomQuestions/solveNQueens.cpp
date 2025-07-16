class Solution {
public:
    vector<vector<string>> result;

    void solve(int row, int n, vector<string>& board,
               vector<bool>& cols, vector<bool>& diag1, vector<bool>& diag2) {
        if (row == n) {
            result.push_back(board);
            return;
        }

        for (int col = 0; col < n; ++col) {
            if (cols[col] || diag1[row + col] || diag2[row - col + n - 1])
                continue;

            board[row][col] = 'Q';
            cols[col] = diag1[row + col] = diag2[row - col + n - 1] = true;

            solve(row + 1, n, board, cols, diag1, diag2);

            
            board[row][col] = '.';
            cols[col] = diag1[row + col] = diag2[row - col + n - 1] = false;
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<bool> cols(n, false);
        vector<bool> diag1(2 * n - 1, false);  
        vector<bool> diag2(2 * n - 1, false);  
        solve(0, n, board, cols, diag1, diag2);
        return result;
    }
};
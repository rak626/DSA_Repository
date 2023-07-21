// N-Queens

class Solution {
    bool isSafe(int row, int col, int n, vector<string> &board) {
        int duprow = row, dupcol = col;
        while (row >= 0 and col >= 0) {
            if (board[row][col] == 'Q') return 0;
            row--;
            col--;
        }
        row = duprow, col = dupcol;
        while (col >= 0) {
            if (board[row][col] == 'Q') return 0;
            col--;
        }
        row = duprow, col = dupcol;
        while (row < n and col >= 0) {
            if (board[row][col] == 'Q') return 0;
            row++;
            col--;
        }

        return 1;
    }
    void findQpos(int col, int n, vector<string> &board,
                  vector<vector<string>> &ans) {
        if (col == n) {
            ans.push_back(board);
            return;
        }
        for (int row = 0; row < n; row++) {
            if (isSafe(row, col, n, board)) {
                board[row][col] = 'Q';
                findQpos(col + 1, n, board, ans);
                board[row][col] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        for (int i = 0; i < n; i++) {
            board[i] = s;
        }
        findQpos(0, n, board, ans);
        return ans;
    }
};

// using extra space to trim down time complexity

class Solution {
    void findQpos(int col, int n, vector<string> &board,
                  vector<vector<string>> &ans, vector<int> &leftrow,
                  vector<int> &upperDig, vector<int> &lowerDig) {
        if (col == n) {
            ans.push_back(board);
            return;
        }
        for (int row = 0; row < n; row++) {
            if (leftrow[row] == 0 and upperDig[n - 1 + col - row] == 0 and
                lowerDig[row + col] == 0) {
                leftrow[row] = 1;
                upperDig[n - 1 + col - row] = 1;
                lowerDig[row + col] = 1;
                board[row][col] = 'Q';
                findQpos(col + 1, n, board, ans, leftrow, upperDig, lowerDig);
                board[row][col] = '.';
                leftrow[row] = 0;
                upperDig[n - 1 + col - row] = 0;
                lowerDig[row + col] = 0;
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        for (int i = 0; i < n; i++) {
            board[i] = s;
        }
        vector<int> leftrow(n, 0), upperDig(2 * n - 1, 0),
            lowerDig(2 * n - 1, 0);

        findQpos(0, n, board, ans, leftrow, upperDig, lowerDig);
        return ans;
    }
};
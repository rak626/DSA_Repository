// sudoko solver

class Solution {
    bool isValid(vector<vector<char>> &board, int row, int col, char c) {
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == c) {
                return false;
            }
            if (board[i][col] == c) {
                return false;
            }
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) {
                return false;
            }
        }
        return true;
    }

    bool solve(vector<vector<char>> &board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (char c = '1'; c <= '9'; c++) {
                        if (isValid(board, i, j, c)) {
                            board[i][j] = c;
                            if (solve(board) == true) {
                                return true;
                            } else {
                                board[i][j] = '.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

public:
    void solveSudoku(vector<vector<char>> &board) { solve(board); }
};

// rat in a maze

class Solution {
    void solve(int row, int col, vector<vector<int>> &m, int n, string move,
               int delrow[], int delcol[], vector<string> &ans,
               vector<vector<int>> &vis) {
        if (row == n - 1 and col == n - 1) {
            ans.push_back(move);
            return;
        }
        string dir = "DLRU";
        for (int i = 0; i < 4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if (nrow >= 0 and nrow < n and ncol < n and ncol >= 0 and
                !vis[nrow][ncol] and m[nrow][ncol] == 1) {
                vis[row][col] = 1;
                solve(nrow, ncol, m, n, move + dir[i], delrow, delcol, ans,
                      vis);
                vis[row][col] = 0;
            }
        }
    }

public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        int delrow[] = {1, 0, 0, -1};
        int delcol[] = {0, -1, 1, 0};
        vector<vector<int>> vis(n, vector<int>(n, 0));
        if (m[0][0] == 1) solve(0, 0, m, n, "", delrow, delcol, ans, vis);
        return ans;
    }
};
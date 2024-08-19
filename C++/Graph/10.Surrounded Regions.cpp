class Solution {
    void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vis[row][col] = 1;
        for (int i = 0; i < 4; i++) {
            int nrow = row + dx[i];
            int ncol = col + dy[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && board[nrow][ncol] == 'O' && vis[nrow][ncol] == 0) {
                vis[nrow][ncol] = 1;
                dfs(nrow, ncol, vis, board);
            }
        }
    }
    int dx[4] = { 0 , 1, 0 , -1 };
    int dy[4] = { 1, 0, -1, 0 };
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        for(int i = 0 ; i < n ; i++){
            if(board[i][0] == 'O' && vis[i][0] == 0) dfs(i, 0, vis, board);
            if(board[i][m-1] == 'O' && vis[i][m-1] == 0) dfs(i, m-1, vis, board);
        }
        for(int i = 0 ; i < m ; i++){
            if(board[0][i] == 'O' && vis[0][i] == 0) dfs(0, i, vis, board);
            if(board[n-1][i] == 'O' && vis[n-1][i] == 0) dfs(n-1, i, vis, board);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m;j++) {
                if (vis[i][j] == 0 && board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
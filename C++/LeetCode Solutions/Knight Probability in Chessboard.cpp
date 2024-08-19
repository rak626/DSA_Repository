class Solution {
    int dx[8] = {1,2,2,1,-1,-2,-2,-1};
    int dy[8] = {2,1,-1,-2,-2,-1,1,2};
    double dp[26][26][102];
    double f(int row ,int col, int n,int k ){
        if(k == 0) return 1;
        if(dp[row][col][k] != -1.0) return dp[row][col][k];
        double cnt = 0;
        for(int i = 0 ; i < 8 ; i++){
            int nrow = row + dx[i];
            int ncol = col + dy[i];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < n ){
                cnt += f(nrow, ncol, n, k - 1);
            }
        }
        return dp[row][col][k] = cnt;
        
    }
public:
    double knightProbability(int n, int k, int row, int col) {
        memset(dp, -1.0, sizeof(dp));
        double position_inside_board = f(row, col, n,k);

        double total_pos = pow(8 , k);
        
        return position_inside_board / total_pos;
    }
};
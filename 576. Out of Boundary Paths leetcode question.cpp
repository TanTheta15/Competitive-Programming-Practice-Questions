/*    576. Out of Boundary Paths
There is an m x n grid with a ball. The ball is initially at the position [startRow, startColumn]. You are allowed to move the ball to one of the four adjacent cells in the grid (possibly out of the grid crossing the grid boundary). You can apply at most maxMove moves to the ball.

Given the five integers m, n, maxMove, startRow, startColumn, return the number of paths to move the ball out of the grid boundary. Since the answer can be very large, return it modulo 109 + 7.

*/

const int M = 1e9 + 7;
    vector<pair<int, int> > movements = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int dp[55][55][55];
    
    int func(int m, int n, int maxMove, int i, int j){
        if(i >= m || i < 0 || j >= n || j < 0) return 1;
        
        if(maxMove <= 0) return 0;
        
        if(dp[i][j][maxMove] != -1) return dp[i][j][maxMove];
        long long res = 0;
        
        for(pair<int, int> &it : movements){
            int row = it.first + i;
            int col = it.second + j;
            res += func(m, n, maxMove - 1, row, col);
        }
        return dp[i][j][maxMove] = res % M;
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp, -1, sizeof(dp));
        return func(m, n, maxMove, startRow, startColumn) % M;
    }

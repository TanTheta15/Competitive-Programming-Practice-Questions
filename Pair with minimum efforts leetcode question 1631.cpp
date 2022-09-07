/*  1631. Path With Minimum Effort
You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.

A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.

Return the minimum effort required to travel from the top-left cell to the bottom-right cell.
*/
int vis[105][105];
    vector<pair<int, int> > movements = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    void dfs(int x, int y, int mid, vector<vector<int> > &heights){
        if(!vis[x][y]){
            int n = heights.size(), m = heights[0].size();
            vis[x][y] = 1;
            for(auto &it : movements){
                int row = it.first + x;
                int col = it.second + y;
                if(row >= 0 && row < n && col >= 0 && col < m){
                    if(abs(heights[row][col] - heights[x][y]) <= mid){
                        dfs(row, col, mid, heights);
                    }
                }
            }
        }
    }
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        int low = 0, high = 1e6 + 10;
        int n = heights.size(), m = heights[0].size();
        while(low < high){
            int mid = (low + high) >> 1;
            memset(vis, 0, sizeof(vis));
            dfs(0, 0, mid, heights);
            if(vis[n - 1][m - 1] == 1)
                high = mid;
            else low = mid + 1;
            
        }
        return low;
    }

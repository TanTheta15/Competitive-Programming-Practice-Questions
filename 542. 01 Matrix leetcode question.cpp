/*    542. 01 Matrix
Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.
*/

vector<pair<int, int> > movements = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; 
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int, int> > q;
        int n = mat.size(), m = mat[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 0){
                    q.push(make_pair(i, j));
                }
                else {
                    mat[i][j] = -1;
                }
            }
        }
        while(!q.empty()){
            pair<int, int> it = q.front();
            q.pop();
            int r = it.first;
            int c = it.second;
            for(pair<int, int> &temp : movements){
                int row = temp.first + r;
                int col = temp.second + c;
                if(row < 0 || col < 0 || row == n || col == m || mat[row][col] != -1){
                    continue;
                }
                mat[row][col] = mat[r][c] + 1;
                q.push(make_pair(row, col));
            }
        }
        return mat;
    }

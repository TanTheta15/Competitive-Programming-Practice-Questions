/*    1584. Min Cost to Connect All Points
You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].

The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.

Return the minimum cost to make all points connected. All points are connected if there is exactly one simple path between any two points.

*/

const static int N = 1e3 + 10;
    int parent[N], rank[N];
    
    int find(int i){
        if(parent[i] == -1) return i;
        else return parent[i] = find(parent[i]);
    }
    
    void Union(int a, int b){
        a = find(a);
        b = find(b);
        
        if(a == b) return ;
        if(rank[b] > rank[a]) swap(a, b);
        
        parent[b] = a;
        rank[a] = rank[b] + 1;
    }
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        memset(parent, -1, sizeof(parent));
        memset(rank, 0, sizeof(rank));
        
        int n = points.size();
        vector<pair<int, pair<int, int> > > dist(n + 1);
        for(int i = 0; i < n - 1; i++){
            for(int j = i + 1; j < n; j++){
                int dis = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                dist.push_back(make_pair(dis, make_pair(i, j)));
            }
        }
        sort(dist.begin(), dist.end());
        int ans = 0;
        for(auto it : dist){
            if(find(it.second.first) != find(it.second.second)){
                ans += it.first;
                Union(it.second.first, it.second.second);
            } 
        }
        return ans;
    }

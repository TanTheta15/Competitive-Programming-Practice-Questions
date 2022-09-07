/*    947. Most Stones Removed with Same Row or Column
On a 2D plane, we place n stones at some integer coordinate points. Each coordinate point may have at most one stone.

A stone can be removed if it shares either the same row or the same column as another stone that has not been removed.

Given an array stones of length n where stones[i] = [xi, yi] represents the location of the ith stone, return the largest possible number of stones that can be removed.

*/

const static int N = 2e4 + 10;
    int parent[N], sz[N];
    
    int find(int u)
    {
        if(parent[u] == -1) return u;
        else return parent[u] = find(parent[u]);
    }
    
    void Union(int a, int b)
    {
        a = find(a);
        b = find(b);
        
        if(a != b)
        {
            if(sz[b] > sz[a])
                swap(a, b);
            parent[b] = a;
            sz[a]++;
        }
    }
    
    int removeStones(vector<vector<int>>& stones) {
        memset(parent, -1, sizeof (parent));
        memset(sz, 1, sizeof (sz));
        for(auto it : stones)
        {
            int row = it[0];
            int col = it[1] + 1e4 + 1;
            Union(row, col);
        }
        
        set<int> s;
        for(auto it : stones)
            s.insert(find(it[0]));
        int comp = s.size();
        
        return stones.size() - comp;
    }

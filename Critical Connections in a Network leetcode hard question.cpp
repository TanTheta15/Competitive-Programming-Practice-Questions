unordered_map<int, vector<int> > adj;

    void DFS(int u, int parent, vector<int> &disc, vector<int> &low, vector<vector<int> > &bridges){
        static int time = 0;
        disc[u] = low[u] = time;
        time += 1;
        for(int v : adj[u]){
            if(v == parent) continue;
            if(disc[v] == -1){ // if node is not visited
                DFS(v, u, disc, low, bridges);
                low[u] = min(low[v], low[u]);

                if(low[v] > disc[u]){
                    bridges.push_back(vector<int> ({u, v}));
                }
            }
            else{
                low[u] = min(low[u], disc[v]);
            }
        }
    }

    void findBridges_Tarjan(int V, vector<vector<int> > &bridges){
        vector<int> disc(V, -1), low(V, -1);
        // apply dfs for each component
        for(int i = 0; i < V; i++){
            if(disc[i] == -1){
                DFS(i, -1, disc, low, bridges);
            }
        }
    }

    vector<vector<int> > criticalConnections(int n, vector<vector<int> > &connections){
        for(auto it : connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<vector<int> > bridges; // store all the bridges pair
        findBridges_Tarjan(n, bridges);
        return bridges;
    }

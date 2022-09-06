unordered_map<int, vector<int> > adj;

    void DFS(int u, vector<int> &disc, vector<int> &low, vector<int> &parent, vector<vector<int> > &bridges){
        static int time = 0;
        disc[u] = low[u] = time;
        time += 1;
        for(int v : adj[u]){
            if(disc[v] == -1){ // if node is not visited
                parent[v] = u;
                DFS(v, disc, low, parent, bridges);
                low[u] = min(low[v], low[u]);

                if(low[v] > disc[u]){
                    bridges.push_back(vector<int> ({u, v}));
                }
            }
            else if(v != parent[u]){
                low[u] = min(low[u], disc[v]);
            }
        }
    }

    void findBridges_Tarjan(int V, vector<vector<int> > &bridges){
        vector<int> disc(V, -1), low(V, -1), parent(V, -1);
        // apply dfs for each component
        for(int i = 0; i < V; i++){
            if(disc[i] == -1){
                DFS(i, disc, low, parent, bridges);
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

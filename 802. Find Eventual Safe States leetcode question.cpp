/*    802. Find Eventual Safe States
There is a directed graph of n nodes with each node labeled from 0 to n - 1. The graph is represented by a 0-indexed 2D integer array graph where graph[i] is an integer array of nodes adjacent to node i, meaning there is an edge from node i to each node in graph[i].

A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node (or another safe node).

Return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.


*/

bool dfs(int s, vector<vector<int> > &graph, vector<bool> &visited, vector<bool> &recSt, 
             vector<bool> &is_presentCycle){
        visited[s] = true;
        recSt[s] = true;
        
        for(auto &it: graph[s]){
            if(!visited[it]){
                if(dfs(it, graph, visited, recSt, is_presentCycle)){
                    return is_presentCycle[s] = true;
                }
            }
            else if(recSt[it]) return is_presentCycle[s] = true;
        }
        recSt[s] = false;
        return false;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> visited(n, false), recSt(n, false);
        vector<bool> is_presentCycle(n, false);
        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                dfs(i, graph, visited, recSt, is_presentCycle);
            }
        }
        
        for(int i = 0; i < n; i++){
            if(!is_presentCycle[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }

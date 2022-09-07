
/*    1514. Path with Maximum Probability
You are given an undirected weighted graph of n nodes (0-indexed), represented by an edge list where edges[i] = [a, b] is an undirected edge connecting the nodes a and b with a probability of success of traversing that edge succProb[i].

Given two nodes start and end, find the path with the maximum probability of success to go from start to end and return its success probability.

If there is no path from start to end, return 0. Your answer will be accepted if it differs from the correct answer by at most 1e-5.

*/

typedef priority_queue<pair<double, int>, vector<pair<double, int> >, greater<pair<double, int> > > MinHeap;

class Graph{
    public : 
    vector<vector<pair<int, double> > > adj;
    
    int nNodes;
    
    void generateGraph(vector<vector<int> > &edges, vector<double> &dist, int n){
        this -> nNodes = n;
        adj.resize(nNodes + 1);
        
        for(int i = 0; i < edges.size(); i++){
            adj[edges[i][0]].push_back(make_pair(edges[i][1], dist[i]));
            adj[edges[i][1]].push_back(make_pair(edges[i][0], dist[i]));
        }
    }
    
    void clear(){
        adj.clear();
    }
};

class Solution {
public:
    
    double dijsktra(Graph g, int source, int target){
        vector<double> dist(g.nNodes + 1, 0);
        // vector<bool> visited(g.nNodes + 1, false);
        
        MinHeap minHeap;
        minHeap.push(make_pair(-1, source));
        dist[source] = -1;
        
        while(!minHeap.empty()){
            pair<double, int> it = minHeap.top();
            double curDist = it.first;
            int u = it.second;
            minHeap.pop();
            if(u ==  target) break;
            // if(visited[u]) continue;
            // visited[u] = true;
            for(auto &temp : g.adj[u]){
                double nextDist = curDist * temp.second;
                int v = temp.first;
                if(dist[v] > nextDist){
                    dist[v] = nextDist;
                    minHeap.push(make_pair(nextDist, v));
                }
            }
        }
        return -dist[target];
    }
    
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        Graph g; 
        g.generateGraph(edges, succProb, n);
        return dijsktra(g, start, end);
    }
};

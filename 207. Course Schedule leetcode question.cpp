/*    207. Course Schedule
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false

*/
bool dfs(vector<int> adj[], vector<bool> &visited, vector<bool> &cur_Visited, int u){
        visited[u] = true;
        cur_Visited[u] = true;
        
        for(auto &it: adj[u]){
            if(!visited[it]){
                if(dfs(adj, visited, cur_Visited, it))
                    return true;
            }
            else if(cur_Visited[it])
                return true;
        }
        cur_Visited[u] = false;
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        
        for(auto &it : prerequisites){
            adj[it[0]].push_back(it[1]);
        }
        vector<bool> visited(numCourses, false);
        vector<bool> cur_Visited(numCourses, false);
        for(int i = 0; i < numCourses; i++){
            if(!visited[i]){
                if(dfs(adj, visited, cur_Visited, i)){
                    return false;
                }
            }
        }
        return true;
        
    }

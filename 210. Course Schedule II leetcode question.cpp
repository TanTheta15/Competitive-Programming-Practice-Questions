/*     210. Course Schedule II
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.

*/
vector<vector<int> > g;
    
    bool dfs(vector<int> &color, vector<int> &res, int i){
        color[i] = 1;
        for(auto &it : g[i]){
            if(!color[it]){
                if(dfs(color, res, it)) return true;
            }
            else if(color[it] == 1) return true;
        }
        color[i] = 2;
        res.push_back(i);
        return false;
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        g.resize(numCourses);
        for(auto &it : prerequisites){
            g[it[0]].push_back(it[1]);
        }
        vector<int> color(numCourses, 0), res;
        
        for(int i = 0; i < numCourses; i++){
            if(!color[i]){
                if(dfs(color, res, i)) return {};
            }
        }
        return res;
    }

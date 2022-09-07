/*    952. Largest Component Size by Common Factor
You are given an integer array of unique positive integers nums. Consider the following graph:

There are nums.length nodes, labeled nums[0] to nums[nums.length - 1],
There is an undirected edge between nums[i] and nums[j] if nums[i] and nums[j] share a common factor greater than 1.
Return the size of the largest connected component in the graph.

*/
const static int N = 1e5 + 10;
    int parent[N], rank[N];

    int find(int i){
        if(parent[i] == -1) return i;
        else return parent[i] = find(parent[i]);
    }
    
    void Union(int a, int b){
        a = find(a);
        b = find(b);
        if(a == b) return;

        if(rank[b] > rank[a]) swap(a, b);
        parent[b] = a;
        rank[a] = rank[b] + 1;

    }
    
    int largestComponentSize(vector<int>& nums) {
        memset(parent, -1, sizeof(parent));
        memset(rank, 1, sizeof(rank));
        for(int i = 0; i < nums.size(); i++){
            for(int k = 2; k <= sqrt(nums[i]); k++){
                if(nums[i] % k == 0){
                    Union(nums[i], k);
                    Union(nums[i], nums[i] / k);
                }
            }
        }
        int ans = 0;
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++){
            int p = find(nums[i]);
            mp[p] += 1;
            ans = max(ans, mp[p]);
        }
        return ans;
    }

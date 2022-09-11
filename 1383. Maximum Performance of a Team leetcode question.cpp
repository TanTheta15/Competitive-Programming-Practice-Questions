/*    1383. Maximum Performance of a Team
You are given two integers n and k and two integer arrays speed and efficiency both of length n. There are n engineers numbered from 1 to n. speed[i] and efficiency[i] represent the speed and efficiency of the ith engineer respectively.

Choose at most k different engineers out of the n engineers to form a team with the maximum performance.

The performance of a team is the sum of their engineers' speeds multiplied by the minimum efficiency among their engineers.

Return the maximum performance of this team. Since the answer can be a huge number, return it modulo 109 + 7.

 

Example 1:

Input: n = 6, speed = [2,10,3,1,5,8], efficiency = [5,4,3,9,7,2], k = 2
Output: 60
Explanation: 
We have the maximum performance of the team by selecting engineer 2 (with speed=10 and efficiency=4) and engineer 5 (with speed=5 and efficiency=7). That is, performance = (10 + 5) * min(4, 7) = 60.
*/
const static int M = 1e9 + 7;
    
    typedef priority_queue<int, vector<int> , greater<int> > MinHeap;
    static bool cmp(pair<int, int> a, pair<int, int> b){
        if(a.first != b.first){
            return a.first > b.first;
        }
        else{
            return a.second > b.second;
        }
    }
    
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int, int> > interval;
        for(int i = 0; i < n; i++){
            pair<int, int> it;
            it.first = efficiency[i];
            it.second = speed[i];
            interval.push_back(it);
        }
        sort(interval.begin(), interval.end(), cmp);
        MinHeap minHeap;
        long long ans = 0;
        long long sum = 0;
        for(int i = 0; i < n; i++){
            pair<int, int> it = interval[i];
            sum += it.second;
            minHeap.push(it.second);
            if(minHeap.size() > k){
                sum -= minHeap.top();
                minHeap.pop();
            }
            ans = max(ans, (sum * it.first));
        }
        return ans % M;
    }

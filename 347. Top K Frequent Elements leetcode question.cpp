/*    347. Top K Frequent Elements
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

 

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
*/
    typedef pair<int, int> pii;
    typedef priority_queue<pii, vector<pii>, greater<pii> > MinHeap;
    typedef unordered_map<int, int> Map;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        MinHeap minHeap;
        Map map;
        for(int it : nums){
            map[it]++;
        }
        for(auto it : map){
            minHeap.push(make_pair(it.second, it.first));
            if(minHeap.size() > k){
                minHeap.pop();
            }
        }
        vector<int> ans;
        while(k--){
            ans.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return ans;
    }

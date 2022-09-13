/*    503. Next Greater Element II
Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), return the next greater number for every element in nums.

The next greater number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, return -1 for this number.

 

Example 1:

Input: nums = [1,2,1]
Output: [2,-1,2]
Explanation: The first 1's next greater number is 2; 
The number 2 can't find next greater number. 
The second 1's next greater number needs to search circularly, which is also 2.
*/
vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans(nums.size(), -1);
        stack<int> st;
        int n = nums.size();
        for(int i = 2 * n - 1; i >= 0; i--){
            while(not st.empty() and st.top() <= nums[i % n]){
                st.pop();
            }
            if(i < n){
                int res = st.empty() == true ? -1 : st.top();
                ans[i % n] = res;
            }
            
            st.push(nums[i % n]);
        }
        return ans;
    }

/*    84. Largest Rectangle in Histogram
Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

 

Example 1:


Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.
*/
    typedef stack<int> stack;
    typedef long long ll;
    
    int largestRectangleArea(vector<int>& heights) {
        stack st;
        ll ans = 0;
        int n = heights.size();
        vector<int> prevSmaller(n, -1);
        vector<int> nextSmaller(n, -1);
        for(int i = 0; i < heights.size(); i++){
            while(not st.empty() and heights[st.top()] >= heights[i]){
                st.pop();
            }
            int res = st.empty() == true ? 0 : st.top() + 1;
            prevSmaller[i] = res;
            st.push(i);
        }
        stack s;
        for(int i = n - 1; i >= 0; i--){
            while(not s.empty() and heights[s.top()] >= heights[i]){
                s.pop();
            }
            int res = s.empty() == true ? n - 1 : s.top() - 1;
            nextSmaller[i] = res;
            s.push(i);
        }
        for(int i = 0; i < n; i++){
            ans = max(ans, heights[i] * 1ll * (nextSmaller[i] - prevSmaller[i] + 1));
        }
        return ans;
    }

  //Efficient Solution
    typedef stack<int> stack;
    typedef long long ll;
    
    int largestRectangleArea(vector<int>& heights) {
        stack st;
        ll ans = 0;
        int n = heights.size();
        for(int i = 0; i <= heights.size(); i++){
            while(not st.empty() and (i == n or heights[st.top()] >= heights[i])){
                int res = heights[st.top()];
                st.pop();
                int width = st.empty() == true ? i : i - st.top() - 1;
                ans = max(ans, res * 1ll * width);
            }
            st.push(i);
        }
        
        return ans;
    }

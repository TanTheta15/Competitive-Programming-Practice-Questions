/*    673. Number of Longest Increasing Subsequence
Given an integer array nums, return the number of longest increasing subsequences.

Notice that the sequence has to be strictly increasing.
*/

int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1, 1), cnt(n + 1, 1);
        int maxLen = 1;
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j]){
                    if(dp[j] + 1 > dp[i]){
                        dp[i] = dp[j] + 1;
                        cnt[i] = cnt[j];
                    }
                    else if(dp[j] + 1 == dp[i]){
                        cnt[i] += cnt[j];
                    }
                }
            }
            maxLen = max(maxLen, dp[i]);
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(dp[i] == maxLen){
                ans += cnt[i];
            }
        }
        return ans;
    }

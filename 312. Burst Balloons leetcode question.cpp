/*    312. Burst Balloons
You are given n balloons, indexed from 0 to n - 1. Each balloon is painted with a number on it represented by an array nums. You are asked to burst all the balloons.

If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1] coins. If i - 1 or i + 1 goes out of bounds of the array, then treat it as if there is a balloon with a 1 painted on it.

Return the maximum coins you can collect by bursting the balloons wisely.

*/

int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int> > dp(n + 2, vector<int> (n + 2, 0));
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        for(int i = n; i >= 1; i--){
            for(int j = 1; j <= n; j++){
                if(i > j) continue;
                int maxi = INT_MIN;
                for(int k = i; k <= j; k++){
                    int steps = nums[i - 1] *1LL* nums[k] * nums[j + 1] + 
                        dp[i][k - 1] + dp[k + 1][j];
                    maxi = max(maxi, steps);
                }
                dp[i][j] = maxi;
            }
        }
        return dp[1][n];
    }

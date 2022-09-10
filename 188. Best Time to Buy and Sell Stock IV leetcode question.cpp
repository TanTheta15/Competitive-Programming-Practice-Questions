/*    188. Best Time to Buy and Sell Stock IV
You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.

Find the maximum profit you can achieve. You may complete at most k transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: k = 2, prices = [2,4,1]
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
*/
int dp[1010][110][2];
    
    int func(vector<int> &prices, int k, int ind, int buy, int n){
        if(k == 0 or ind == n) return 0;
        if(dp[ind][k][buy] != -1) return dp[ind][k][buy];
        
        if(buy == 1){
            return dp[ind][k][buy] = max(-prices[ind] + func(prices, k, ind + 1, 0, n), 
                       func(prices, k, ind + 1, 1, n));
        }
        else {
            return dp[ind][k][buy] = max(prices[ind] + func(prices, k - 1, ind + 1, 1, n), 
                      func(prices, k, ind + 1, 0, n));
        }
    }
    
    int maxProfit(int k, vector<int>& prices) {
        memset(dp, -1, sizeof(dp));
        return func(prices, k, 0, 1, prices.size());
    }

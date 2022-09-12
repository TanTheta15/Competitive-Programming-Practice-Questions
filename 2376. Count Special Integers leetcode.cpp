/*    2376. Count Special Integers
We call a positive integer special if all of its digits are distinct.

Given a positive integer n, return the number of special integers that belong to the interval [1, n].

 

Example 1:

Input: n = 20
Output: 19
Explanation: All the integers from 1 to 20, except 11, are special. Thus, there are 19 special integers.
*/
class Solution {
    private: 
    int dp[11][2][1024];
    int gogo(string &s, int pos = 0, int tight = 1, int mask = 0)
    {
        if(pos == s.size())
            return mask != 0;
        if(dp[pos][tight][mask] != -1)
            return dp[pos][tight][mask];
        int ans = 0;
        if(tight == 1)
        {
            for(int i = 0; i <= s[pos] - '0'; i++)
            {
                if(mask & (1 << i))
                    continue;
                else
                {
                    int newMask = (mask == 0 && i == 0 ? mask : (mask | (1 << i)));
                    
                    if(i == s[pos] - '0')
                        ans += gogo(s, pos + 1, 1, newMask);
                    else 
                        ans += gogo(s, pos + 1, 0, newMask);
                }
            }
        }
        else
        {
            for(int i = 0; i <= 9; i++)
            {
                if(mask & 1 << i)
                    continue;
                int newMask = (mask == 0 && i == 0 ? mask : (mask | (1 << i)));
                ans += gogo(s, pos + 1, 0, newMask);
            }
        }
        return dp[pos][tight][mask] = ans;
    }
public:
    int countSpecialNumbers(int n) {
        string s = to_string(n);
        memset(dp, -1, sizeof(dp));
        return gogo(s);
    }
};

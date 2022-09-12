/*    357. Count Numbers with Unique Digits
Given an integer n, return the count of all numbers with unique digits, x, where 0 <= x < 10n.

 

Example 1:

Input: n = 2
Output: 91
Explanation: The answer should be the total numbers in the range of 0 ≤ x < 100, excluding 11,22,33,44,55,66,77,88,99
*/
int countNumbersWithUniqueDigits(int n) {
        if(n == 0) return 1;
        int ans = 10;
        int start = 9;
        int current = 9;
        while(n-- > 1){
            current *= (start--);
            ans += current;
        }
        return ans;
    }

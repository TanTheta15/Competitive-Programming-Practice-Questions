/*    1680. Concatenation of Consecutive Binary Numbers
Given an integer n, return the decimal value of the binary string formed by concatenating the binary representations of 1 to n in order, modulo 109 + 7.

 

Example 1:

Input: n = 1
Output: 1
Explanation: "1" in binary corresponds to the decimal value 1. 
Example 2:

Input: n = 3
Output: 27
Explanation: In binary, 1, 2, and 3 corresponds to "1", "10", and "11".
After concatenating them, we have "11011", which corresponds to the decimal value 27.
*/
const static int M = 1e9 + 7;
    
    int concatenatedBinary(int n) {
        long long ans = 0;
        for(int i = 1; i <= n; i++){
            int no_of_bits = log2(i) + 1;
            ans = ((ans << no_of_bits) % M + i) % M;
        }
        return ans;
    }

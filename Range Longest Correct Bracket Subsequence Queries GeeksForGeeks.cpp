/*    Range Longest Correct Bracket Subsequence Queries
Given a bracket sequence or in other words a string S of length N and queries Q, consisting of characters ‘(‘ and ‘)’. Find the length of the maximum correct bracket subsequence of sequence for a given query range from L to R(L and R inclusive).

Note: A correct bracket sequence is the one that has matched bracket pairs or which contains another nested correct bracket sequence.

Example 1:

Input:
S = ())(())(())( , Q = 2
Queries = {(3,6), (0,11)}
Output:
4
10
Explanation: For query 1, Longest Correct
Bracket Subsequence is (()).Hence length=4
For query 2, Longest Correct Bracket
Subsequence is ()(())(()). Hence length=10
*/
Node getP(Node st[], int qs, int qe, int ss, int se, int ind){
        if(qs > se or qe < ss){
            Node nullNode;
            return nullNode;
        }
        if(qs <= ss and qe >= se){
            return st[ind];
        }
        int mid = (ss + se) >> 1;
        return merge(getP(st, qs, qe, ss, mid, 2 * ind + 1), 
                    getP(st, qs, qe, mid +1, se, 2 * ind + 2));
    }
    
    int getLongestSequence(Node* st, string str, int qs, int qe, int n) 
    {
        // add code here
        Node res = getP(st, qs, qe, 0, n - 1, 0);
        return res.pairs * 2;
    }

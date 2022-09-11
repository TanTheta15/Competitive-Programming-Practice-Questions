/*    131. Palindrome Partitioning
Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

A palindrome string is a string that reads the same backward as forward.

 

Example 1:

Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]
*/
void func(string &s, vector<string> &path, vector<vector<string> > &ans, int ind){
        if(ind == s.length()){
            ans.push_back(path);
            return ;
        }
        for(int j = ind; j < s.length(); j++){
            if(isPalindrome(s, ind, j)){
                path.push_back(s.substr(ind, j - ind + 1));
                func(s, path, ans, j + 1);
                path.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<string> path;
        vector<vector<string> > ans;
        func(s, path, ans, 0);
        return ans;
    }
    
    bool isPalindrome(string &s, int low, int high){
        while(low <= high){
            if(s[low++] != s[high--]){
                return false;
            }
        }
        return true;
    }

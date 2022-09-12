/*    Range GCD Queries
You are given an array arr of size N, and Q queries.  You have to find GCD of the elements in the given range alongside updating the value of the array as per query.
Note: 0-based indexing is used.

Example 1:

Input:
N = 6, Q = 3
arr[] = {2,3,4,6,8,16}
Queries = findRangeGCD(0,2)
          updateValue(3,8)
          findRangeGCD(2,5)
Output:
1
4
Explanation: There are 3 queries: 
Query 1 : gcd(2, 3, 4) = 1
Query 2 : 6 changes to 8
Query 3 : gcd(4, 8, 8, 16) = 4
*/
int findRange(int st[], int ind, int ss, int se, int l, int r){
        if(l > se or r < ss){
            return 0;
        }
        if(l <= ss and r >= se){
            return st[ind];
        }
        int mid = (ss + se) >> 1;
        return __gcd(findRange(st, 2 * ind + 1, ss, mid, l, r),
                    findRange(st, 2 * ind + 2, mid + 1, se, l, r));
    }
    
    int findRangeGcd(int l, int r, int st[], int n) 
    {
        findRange(st, 0, 0, n - 1, l, r);
    }
    
    //Function to update a value in input array and segment tree.
    
    void Update(int arr[], int index, int new_val, int st[], int ss, int se, int ind){
        if(index < ss or index > se){
            return ;
        }
        if(index == ss and index == se){
            st[ind] = new_val;
            arr[index] = new_val;
            return ;
        }
        if(ss < se){
            int mid = (ss + se) >> 1;
            Update(arr, index, new_val, st, ss, mid, 2 * ind + 1);
            Update(arr, index, new_val, st, mid + 1, se, 2 * ind + 2);
            st[ind] = __gcd(st[2 * ind + 1], st[2 * ind + 2]);
        }
    }
    
    void updateValue(int index, int new_val, int *arr, int st[], int n) 
    {
        Update(arr, index, new_val, st, 0, n - 1, 0);
    }

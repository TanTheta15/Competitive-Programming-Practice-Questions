/*    Range Sum Queries
You are given an array arr[] of size N and Q queries. 
getSum(L,R):  return the sum of range [L,R]
updateValue(index,value): update arr[index] to value.

You need to calculate the answer for Type-1 queries and do the update in the segment tree for Type-2 queries.

Note: 0-based indexing is used.

Example 1:

Input:
N = 6, Q = 3
arr[] = {1,3,5,7,9,11}
Queries = getSum(0,2)
          updateValue(3,17)
          getSum(0,5)
Output:
9
46
Explanation: There are 3 queries: 
Query 1: 1 + 3 + 5 = 9
Query 2: 7 changes to 17
Query 3: 1 + 3 + 5 + 17 + 9 + 11= 46
*/

void Update(ll st[], int ss, int se, int ind, int diff, int index){
    if(index > se or index < ss) return ;
    st[ind] = st[ind] + diff;
    if(ss < se){
        int mid = (ss + se) >> 1;
        Update(st, ss, mid, 2 * ind + 1, diff, index);
        Update(st, mid + 1, se, 2 * ind + 2, diff, index);
    }
}


void updateValue(int *arr, ll *st, int n, int index, int new_val) 
{
    // add code here
    int diff = new_val - arr[index];
    arr[index] = new_val;
    int ss = 0, se = n - 1, ind = 0;
    Update(st, ss, se, ind, diff, index);
}

//Function to return sum of elements in range from index qs (query start)
//to qe (query end).

ll sum(ll st[], int l, int r, int ss, int se, int ind){
    if(se < l or ss > r){
        return 0;
    }
    if(l <= ss and r >= se){
        return st[ind];
    }
    int mid = (ss + se) >> 1;
    
    return sum(st, l, r, ss, mid, 2 * ind + 1) + sum(st, l, r, mid + 1, se, 2 * ind + 2);
}

ll getsum(ll *st, int n, int l, int r)
{
    // add code here
    int ss = 0, se = n - 1, ind = 0;
    return sum(st, l, r, ss, se, ind);
}

/*    Merge k Sorted Arrays
Given K sorted arrays arranged in the form of a matrix of size K*K. The task is to merge them into one sorted array.
Example 1:

Input:
K = 3
arr[][] = {{1,2,3},{4,5,6},{7,8,9}}
Output: 1 2 3 4 5 6 7 8 9
Explanation:Above test case has 3 sorted
arrays of size 3, 3, 3
arr[][] = [[1, 2, 3],[4, 5, 6], 
[7, 8, 9]]
The merged list will be 
[1, 2, 3, 4, 5, 6, 7, 8, 9].
*/
//Naive Aproach
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        //code here
        vector<int> ans;
        for(vector<int> &it : arr){
            for(int &temp : it){
                ans.push_back(temp);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
    
    // Efficient Aproach
    class Solution
    {
    public:
    //Function to merge k sorted arrays.
    
    class Triplet{
        public : 
                int value;
                int aPos;
                int vPos;
                
                Triplet(int val, int apos, int vpos){
                    this -> value = val;
                    this -> aPos = apos;
                    this -> vPos = vpos;
                }
    };
    
    struct myComp{
        bool operator()(Triplet &a, Triplet &b){
            return a.value > b.value;
        }
    };
    
    typedef priority_queue<Triplet, vector<Triplet>, myComp> MinHeap;
    
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        //code here
        MinHeap minHeap;
        vector<int> ans;
        for(int i = 0; i < arr.size(); i++){
            Triplet t(arr[i][0], i, 0);
            minHeap.push(t);
        }
        while(not minHeap.empty()){
            Triplet t = minHeap.top();
            minHeap.pop();
            ans.push_back(t.value);
            int v = t.vPos;
            if(v + 1 < arr[t.aPos].size()){
                Triplet it(arr[t.aPos][v + 1], t.aPos, v + 1);
                minHeap.push(it);
            }
        }
        return ans;
    }
};

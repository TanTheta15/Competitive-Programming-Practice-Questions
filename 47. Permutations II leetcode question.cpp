/*    47. Permutations II
Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.

 

Example 1:

Input: nums = [1,1,2]
Output:
[[1,1,2],
 [1,2,1],
 [2,1,1]]
*/
vector<vector<int> > ans;
    
    void func(vector<int> &nums, int ind){
        if(ind == nums.size()){
            ans.push_back(nums);
            return ;
        }
        unordered_set<int> s;
        for(int i = ind; i < nums.size(); i++){
            if(s.find(nums[i]) != s.end()) continue;
            s.insert(nums[i]);
            swap(nums[i], nums[ind]);
            func(nums, ind + 1);
            swap(nums[i], nums[ind]);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        // sort(nums.begin(), nums.end());
        func(nums, 0);
        return ans;
    }

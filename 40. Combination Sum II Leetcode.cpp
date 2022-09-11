/*    40. Combination Sum II
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

 

Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
*/
void findCombination(vector<vector<int>>& res, const int order, const int target, vector<int>& local, const vector<int>& num)
    {
        if(target==0)
        {
            res.push_back(local);
            return;
        }
        else
        {
            for(int i = order; i < num.size(); i++) // iterative component
            {
                if(num[i] > target) return;
                if(i && num[i] == num[i-1] && i > order) continue; // check duplicate combination
                local.push_back(num[i]),
                findCombination(res, i + 1, target - num[i], local, num); // recursive componenet
                local.pop_back();
            }
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int> > ans;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        findCombination(ans, 0, target, temp, candidates);
        return ans;
    }

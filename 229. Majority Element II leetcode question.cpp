/*    229. Majority Element II
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

 

Example 1:

Input: nums = [3,2,3]
Output: [3]

*/
vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int sz = nums.size();
        int count1 = 0, count2 = 0, num1 = -1, num2 = -1;
        for(auto it: nums)
        {
            if(it == num1)
                count1++;
            else if(it == num2)
                count2++;
            else if(count1 == 0)
            {
                num1 = it;
                count1 = 1;
            }
            else if(count2 == 0)
            {
                num2 = it;
                count2 = 1;
            }
            else 
            {
                count1--;
                count2--;
            }
        }
        count1 = 0, count2 = 0;
        for(auto it: nums)
        {
            if(it == num1)
                count1++;
            else if(it == num2)
                count2++;
        }
        if(count1 > sz/3)
            ans.push_back(num1);
        if(count2 > sz/3)
            ans.push_back(num2);
        return ans;
    }

Given an array nums of n integers, 
return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target

You may return the answer in any order.

 

Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

Example 2:

Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res; 
        if (nums.size() < 4) {
            return res;
        }
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int target_2;
        int a, b, c, d;
        for (int i = 0; i < n; i++) {
            a = nums[i];
            for (int j = i + 1; j < n; j++) {
                b = nums[j];
                target_2 = target - a - b;
                int k = j + 1;
                int l = n - 1;
                while (k < l) {
                    c = nums[k];
                    d = nums[l];
                    if (c + d == target_2) {
                        res.push_back({a, b, c, d});
                        while (k < l && nums[k] == c) k++;
                        while (k < l && nums[l] == d) l--;
                    }
                    else 
                        c + d > target_2 ? --l : ++k;
                }
                while (j + 1 < n && nums[j + 1] == b) j++;
            }
            while (i + 1 < n && nums[i + 1] == a) i++;
        }
        return res;
    }
};

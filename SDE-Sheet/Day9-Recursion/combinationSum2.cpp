//Leetcode
// The solution set must not contain duplicate combinations.
// Also the sets must be in sorted order.

// Example 1:

// Input: candidates = [10,1,2,7,6,1,5], target = 8
// Output: 
// [
// [1,1,6],
// [1,2,5],
// [1,7],
// [2,6]
// ]

class Solution {
public:
    void func(int index, int target, vector<int>& nums, vector<int>& ds, vector<vector<int>>& ans){
        if(target == 0){
            ans.push_back(ds);
            return;
        }
        for(int i = index; i < nums.size(); i++){
            if(i > index && nums[i] == nums[i-1]) continue;
            if(nums[i] > target) break;
            ds.push_back(nums[i]);
            func(i+1, target-nums[i], nums, ds, ans);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(candidates.begin(),candidates.end());
        func(0, target, candidates, ds, ans);
        return ans;
    }
};
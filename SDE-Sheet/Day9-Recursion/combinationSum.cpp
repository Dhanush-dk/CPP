//Leetcode Soln
//Input: candidates = [2,3,6,7], target = 7
// Output: [[2,2,3],[7]]
// Explanation:
// 2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
// 7 is a candidate, and 7 = 7.
// These are the only two combinations.
class Solution {
public:
    void func(int i,int target,vector<int>& nums,vector<int>& ds,vector<vector<int>>& ans){
        if(i == nums.size()) return;
        else if(target == 0){
            ans.push_back(ds);
            return;
        }
        else if(nums[i] <= target){
            ds.push_back(nums[i]);
            func(i, target-nums[i],nums,ds,ans);
            ds.pop_back();
        }
        func(i+1, target, nums, ds, ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        func(0, target, candidates, ds, ans);
        return ans;
    }
};
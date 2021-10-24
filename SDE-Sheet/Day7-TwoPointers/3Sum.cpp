class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end()); 
        vector<vector<int>> ans; 
        for (int i = 0; i < nums.size(); ++i) 
            if (i == 0 || nums[i-1] != nums[i]) 
                for (int lo = i+1, hi = nums.size()-1; lo < hi; ) {
                    int sm = nums[i] + nums[lo] + nums[hi]; 
                    if (sm < 0) ++lo; 
                    else if (sm == 0) {
                        ans.push_back({nums[i], nums[lo], nums[hi]}); 
                        ++lo; 
                        while (lo < hi && nums[lo-1] == nums[lo]) ++lo; 
                    } else --hi; 
                }
        return ans; 
    }
};
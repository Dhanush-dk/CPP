class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0, high = nums.size() - 2;
        while(low <= high){
            int mid = (low + high) / 2;
            if(mid % 2 == 1){
                if(nums[mid - 1] == nums[mid]) low = mid + 1;
                else high = mid - 1;
            }
            else{
                if(nums[mid + 1] == nums[mid]) low = mid + 1;
                else high = mid - 1;
            }
            // we can simplify the above if else to below code using XOR
            // if(nums[mid] == nums[mid^1]) low = mid + 1;
            // else high = mid - 1;
        }
        return nums[low];
    }
};
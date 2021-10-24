class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int i = 0;
        int j = 1;
        while(j < nums.size()){
            if(nums[i] != nums[j]) nums[++i] = nums[j];
            j++;
        }
        return i+1;
        // if(nums.size()> 0){
        //     int j = 0;
        //     nums[j++] = nums[0];
        //     for(int i = 1; i < nums.size() ; i++){
        //         if(nums[j-1] != nums[i])
        //             nums[j++] = nums[i];
        //     }
        //     return j;
        // }
        // else
        //     return 0;
    }
};
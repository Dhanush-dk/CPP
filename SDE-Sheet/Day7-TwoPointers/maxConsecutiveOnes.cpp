class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi = 0;
        int m = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > 0){
                maxi++;
            }
            else maxi = 0;
            m = max(m,maxi);
        }
        return m;
    }
};
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

Example 1:
Input: nums = [3,2,3]
Output: [3]

Example 2:
Input: nums = [1]
Output: [1]

Example 3:
Input: nums = [1,2]
Output: [1,2]

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n1 = -1;
        int n2 = -1;
        int c1 = 0;
        int c2 = 0;
        for(int i = 0; i < nums.size(); i++){
            if(n1 == nums[i]) c1++;
            else if(n2 == nums[i]) c2++;
            else if(c1 == 0){
                n1 = nums[i];
                c1 = 1;
            }
            else if(c2 == 0){
                n2 = nums[i];
                c2 = 1;
            }
            else{
                c1--;
                c2--;
            }
        }
        vector<int> ans;
        c1 = c2 = 0;
        for(int i = 0; i < nums.size(); i++){
            if(n1 == nums[i]) c1++;
            else if(n2 == nums[i]) c2++;
        }
        if(c1 > nums.size()/3) ans.push_back(n1);
        if(c2 > nums.size()/3) ans.push_back(n2);
        return ans;
    }
};
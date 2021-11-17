Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
You must write an algorithm that runs in O(n) time.

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> st;
        for(auto i: nums)
            st.insert(i);
        int i = 0;
        int max = 0;
        while(i < nums.size()){
            int count = 0;
            if(st.find(nums[i] - 1) != st.end())
                i++;
            else{
                int j = 1;
                while(st.find(nums[i] + j) != st.end()){
                    j++;
                }
                count = j;
                i++;
            }
            if(count > max)
                max = count;
        }
        return max;
    }
};
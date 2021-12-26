class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        set<int> s;
        
        for(auto i: nums)
            s.insert(i);
        
        int maxCount = 0;
        
        for(auto i : nums){
            if(!s.count(i-1)){  // check if number doesn't exist
                int currNum = i;
                int currMax = 1;
                while(s.count(i+1)){
                    currMax++;
                    i += 1;
                }
                maxCount = max(currMax, maxCount);
            }
        }
        return maxCount;
    }
};

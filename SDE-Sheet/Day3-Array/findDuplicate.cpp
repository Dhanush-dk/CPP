//Soln 1
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> m;
        for(int i = 0; i < nums.size(); i++){
            m[nums[i]]++;
        }
        for(auto i: m){
            if(i.second > 1)
                return i.first;
        }
        return 0;
    }
};


//Soln 2

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> map;
        for(int i = 0; i < nums.size(); i++){
            map[nums[i]]++;
            if(map[nums[i]] > 1) return nums[i];
        }
        return 0;
    }
};

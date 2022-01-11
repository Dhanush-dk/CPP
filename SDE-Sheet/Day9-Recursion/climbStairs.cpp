class Solution {
public:
    int findSteps(int goal, int *count){
        if(goal == 0 || goal == 1) return (*count)++;
        // if(goal < 0) return *count;
        findSteps(goal-1, count);
        findSteps(goal-2, count);
        return *count;
    }
    int climbStairs(int n) {
        int count = 0;
        return count = findSteps(n, &count);
    }
};

// This problem is nothing but finding i'th Fibonacci number
class Solution {
public:
    int findWays(int n, int dp[]){
        if(n <= 1) 
            return 1;
        if(dp[n] != -1) 
            return dp[n];
        return dp[n] = findWays(n-1, dp) + findWays(n-2, dp);
    }
    int climbStairs(int n) {
        int dp[n+1];
        memset(dp, -1, sizeof(dp));
        return findWays(n, dp);
    }
};

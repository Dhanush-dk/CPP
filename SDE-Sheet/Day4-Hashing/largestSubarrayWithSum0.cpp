//GFG

Input:
N = 8
A[] = {15,-2,2,-8,1,7,10,23}

Output: 5
Explanation: The largest subarray with sum 0 will be -2 2 -8 1 7.

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        unordered_map<int,int> map;
        int sum = 0;
        int maxi = 0; 
        for(int i = 0; i < n; i++){
            sum += A[i];
            if(sum == 0){
                maxi = i + 1;
            }
            else{
                if(map.find(sum) != map.end()){
                    maxi = max(maxi, i - map[sum]);
                }
                else
                    map[sum] = i;
            }
        }
        return maxi;
    }
};
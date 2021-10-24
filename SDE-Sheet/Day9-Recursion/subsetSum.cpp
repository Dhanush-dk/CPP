//GFG
class Solution
{
public:
    void func(int i, int sum, vector<int>&arr, vector<int>&subsetSums, int N){
        if(i == N){
            subsetSums.push_back(sum);
            return;
        }
        func(i + 1, sum + arr[i], arr, subsetSums, N);
        func(i + 1, sum, arr, subsetSums, N);
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int> subsetSums;
        func(0 ,0 ,arr ,subsetSums ,N);
        sort(subsetSums.begin(),subsetSums.end());
        return subsetSums;
    }
};
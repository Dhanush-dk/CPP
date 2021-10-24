class Solution 
{
    public:
    static bool comparator(struct Job arr1, Job arr2){
        return (arr1.profit > arr2.profit);
    }
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    {
        // your code here
        sort(arr, arr+n ,comparator);
        vector<int> v(n,-1);
        int profit = 0;
        int j = 0;
        for(int i = 0; i < n; i++){
            if(v[arr[i].dead - 1] != -1){
                for(int k = arr[i].dead - 2; k >= 0; k--){
                    if(v[k] == -1){ 
                        v[k] = arr[i].id;
                        profit += arr[i].profit;
                        j++;
                        break;
                    }
                }
            }
            else{
                v[arr[i].dead - 1] = arr[i].id;
                profit += arr[i].profit; 
                j++;
            }
        }
        vector<int> res;
        res.push_back(j);
        res.push_back(profit);
        return res;
    } 
};
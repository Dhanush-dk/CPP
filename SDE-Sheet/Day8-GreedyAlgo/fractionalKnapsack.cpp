class Solution
{
    public:
    static bool compare(struct Item i1,Item i2){
        double r1 = (double)i1.value / (double)i1.weight;
        double r2 = (double)i2.value / (double)i2.weight;
        return (r1 > r2); 
    }
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        sort(arr, arr + n,compare);
        double tot_prof = 0.0;
        int currWeight = 0;
        for(int i = 0; i < n; i++){
            if(currWeight + arr[i].weight <= W){
                currWeight += arr[i].weight;
                tot_prof += arr[i].value;
            }
            else{
                int remain = W - currWeight;
                tot_prof += (arr[i].value / (double)arr[i].weight)* (double)remain;
                break;
            }
        }
        return tot_prof;
    }
        
};
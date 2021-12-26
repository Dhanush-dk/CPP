class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = prices[0];
        int profit = 0;
        int size = prices.size();
        for(int i = 0; i < size; i++){ 
            if(prices[i] < min)
                min = prices[i];
            profit = max(profit, prices[i] - min);
        }
        return profit;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];
        int profit = 0;
        int maxProfit = 0;
        int n = prices.size();
        for(int i=1;i<n;i++){
            if(minPrice>prices[i]){
                minPrice = prices[i];
            }
            profit = prices[i] - minPrice;
            maxProfit = max(profit,maxProfit);
        }
        return maxProfit;
    }
    /*
    Time Complexity - O(n)

    Space Complexity - O(1)
    */
};
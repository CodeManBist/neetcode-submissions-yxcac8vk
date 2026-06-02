class Solution {
public:
    int maxProfit(vector<int>& prices) {

        if(prices.size() == 1) return 0;
        if(prices.size() == 0) return -1;
    
        int bestBuy = prices[0];
        int maxPro = INT_MIN;
        for(int i = 1; i < prices.size(); i++) {
            bestBuy = min(bestBuy, prices[i]);
            maxPro = max(maxPro, prices[i] - bestBuy);
        }

        return maxPro;
    }
};

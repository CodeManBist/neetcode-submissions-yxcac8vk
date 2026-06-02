class Solution {
public:
    int maxProfit(vector<int>& prices) {

        if(prices.size() <= 1) return 0;
    
        int bestBuy = prices[0];
        int maxPro = 0;
        for(int i = 1; i < prices.size(); i++) {
            maxPro = max(maxPro, prices[i] - bestBuy);
            bestBuy = min(bestBuy, prices[i]);
        }

        return maxPro;
    }
};

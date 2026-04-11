class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int bestBuy = prices[0];
        int mProfit = 0;

        for(int i = 1; i < prices.size(); i++) {
            bestBuy = min(bestBuy, prices[i]);
            mProfit = max(mProfit, prices[i] - bestBuy);
        }
        return mProfit;
    }
};

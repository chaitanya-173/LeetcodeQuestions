class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxDiff = 0, minPrice = prices[0];
        for(int i=0; i<prices.size(); i++) {
            minPrice = min(minPrice, prices[i]);
            maxDiff = max(maxDiff, prices[i] - minPrice);
        }
        return maxDiff;
    }
};
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> curr(2, 0);
        vector<int> next(2, 0);
        for (int i = n-1; i >= 0; i--) {
            curr[1] = max(-prices[i] + next[0], next[1]);
            curr[0] = max(prices[i] + next[1], next[0]);
            next = curr;
        }
        return curr[1];
    }
};
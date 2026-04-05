class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> ans;

        int maxCandies = *max_element(candies.begin(), candies.end());

        for(int x : candies) {
            if(x + extraCandies >= maxCandies) ans.push_back(true); 
            else ans.push_back(false);
        }

        return ans;
    }
};
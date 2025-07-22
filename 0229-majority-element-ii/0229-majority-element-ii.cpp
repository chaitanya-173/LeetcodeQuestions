class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> freq;
        for(auto i: nums) {
            freq[i]++;
        }
        vector<int> ans;
        for(auto i: freq) {
            if(i.second > n/3) ans.push_back(i.first);
        }
        return ans;
    }
};
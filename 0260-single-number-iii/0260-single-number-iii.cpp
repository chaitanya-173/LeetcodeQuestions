class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int,int> freq;
        vector<int> ans;
        for(int x: nums) freq[x]++;

        for(auto it: freq) {
            if(it.second == 1) ans.push_back(it.first);
        }
        return ans;
    }
};
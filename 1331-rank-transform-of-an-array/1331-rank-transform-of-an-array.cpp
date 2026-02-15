class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> sortedArr = arr;
        sort(sortedArr.begin(), sortedArr.end());
        
        unordered_map<int,int> mp;
        int rank = 1;
        
        for(auto it: sortedArr) {
            if(mp.count(it) == 0) {
                mp[it] = rank++;
            }
        }
        
        vector<int> ans;
        for(auto it: arr) {
            ans.push_back(mp[it]);
        }
        
        return ans;
    }
};
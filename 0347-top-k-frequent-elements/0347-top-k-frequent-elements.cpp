class Solution {
public:
  static bool check(pair<int,int>a,pair<int,int>b){
        return a.second>b.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(auto x:nums){
            mp[x]++;
        }
        vector<pair<int,int>>ans;
        for(auto &x:mp){
            ans.push_back({x.first,x.second});
        }
        sort(ans.begin(),ans.end(),check);
        vector<int>real;
        for(int i=0;i<k;i++){
            real.push_back(ans[i].first);
        }
        return real;
    }
};
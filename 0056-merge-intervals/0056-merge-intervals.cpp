class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        int start = intervals[0][0];
        int end = intervals[0][1];

        for(auto &it: intervals) {
            int first = it[0];
            int second = it[1];

            if(first <= end) end = max(end, second);
            else {
                ans.push_back({start, end});
                start = first;
                end = second;
            } 
        }
        
        ans.push_back({start, end});
        return ans;
    }
};
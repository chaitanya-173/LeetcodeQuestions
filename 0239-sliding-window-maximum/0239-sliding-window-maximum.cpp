class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;   // store indices
        vector<int> ans;

        for(int i = 0; i < n; i++) {

            // window se bahar wala index hatao
            if(!dq.empty() && dq.front() == i - k) {
                dq.pop_front();
            }
            
            // chhote elements hatao (back se)
            while(!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }

            // current index add karo
            dq.push_back(i);

            // answer tab push karo jab window ban jaaye
            if(i >= k - 1) ans.push_back(nums[dq.front()]);
        }
        
        return ans;
    }
};

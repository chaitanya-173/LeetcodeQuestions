class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n), suf(n), ans(n);

        pre[0] = nums[0];
        for(int i = 1; i < n; i++) {
            pre[i] = max(pre[i-1], nums[i]);
        }

        suf[n-1] = nums[n - 1];
        for(int i = n-2; i >= 0; i--) {
            suf[i] = min(suf[i+1], nums[i]);
        }

        // last index can always reach at least itself
        ans[n-1] = pre[n-1];

        for(int i = n-2; i >= 0; i--) {
            if(pre[i] > suf[i+1]) { // left side has some larger val that can jump into right side (both belong to same component)
                ans[i] = ans[i+1];
            }
            else {
                ans[i] = pre[i]; // best reachable max = prefix max till here
            }
        }

        return ans;
    }
};

// arr => 3, 1, 4, 2, 5
// pre => 3, 3, 4, 4, 5
// suf => 1, 1, 2, 2, 5
// ans => 4, 4, 4, 4, 5

// ind 0 -> 3 -> 2  (max: 4)
// ind 1 -> 0 -> 3 -> 2  (max: 4)
// ind 2 -> 3 -> 1  (max: 4)
// ind 3 -> 2  (max: 4)
// ind 5 (max: 5)
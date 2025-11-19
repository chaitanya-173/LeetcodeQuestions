class Solution {
public:
    int countPartitions(vector<int>& arr, int diff) {
        int totalSum = accumulate(arr.begin(), arr.end(), 0); 
        if((totalSum - diff) % 2 != 0 || (totalSum - diff) < 0) return 0;
        int k = ((totalSum - diff)/2);
        
        int n = arr.size();
        vector<int> prev(k+1, 0);
        prev[0] = 1;
        if(arr[0] <= k) prev[arr[0]]++;
        
        for(int i=1; i<n; i++) {
            vector<int> curr(k+1, 0);
            curr[0] = 1;
            for(int j=0; j<=k; j++) {
                int notPick = prev[j];
                int pick = (arr[i] <= j ? prev[j-arr[i]] : 0);
                curr[j] = notPick + pick;
            }
            prev = curr;
        }
        
        return prev[k];
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return countPartitions(nums, target);
    }
};
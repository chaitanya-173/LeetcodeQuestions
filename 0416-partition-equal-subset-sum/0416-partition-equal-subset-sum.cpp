class Solution {
public:
    bool canPartition(vector<int>& arr) {
        int n = arr.size();
        int sum = 0;
        for(int i=0; i<n; i++) sum += arr[i];
        if(sum % 2 != 0) return false;

        int target = sum/2;
        vector<bool> prev(target+1, 0); 
        prev[0] = 1;

        for(int i=1; i<n; i++) {
            vector<bool> curr(target+1, 0);
            curr[0] = 1;
            for(int j=1; j<=target; j++) {
                bool notPick = prev[j];
                bool pick = false;
                if(arr[i] <= j) pick = prev[j-arr[i]];
                curr[j] = notPick || pick;
            }
            prev = curr;
        }

        return prev[target];
         
    }
};
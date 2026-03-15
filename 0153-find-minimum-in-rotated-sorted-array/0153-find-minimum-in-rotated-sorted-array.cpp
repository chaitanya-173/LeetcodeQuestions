class Solution {
public:
    int findMin(vector<int>& arr) {
        int n = arr.size();
        int low = 0, high = n-1;
        int mini = INT_MAX;
        
        while(low <= high) {
            int mid = low + (high - low) / 2;

            // identify the sorted half
            if(arr[low] <= arr[mid]) {  // left half is sorted
                mini = min(mini, arr[low]);
                low = mid + 1;
            } else {  // right half is sorted
                mini = min(mini, arr[mid]);
                high = mid - 1;
            }
        }

        return mini;
    }
};
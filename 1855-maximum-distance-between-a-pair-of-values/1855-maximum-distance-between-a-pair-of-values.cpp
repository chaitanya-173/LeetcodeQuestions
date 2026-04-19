class Solution {
private:
    int lowerBound(int low, vector<int> &arr, int x) {
        int high = arr.size()-1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(arr[mid] >= x) low = mid + 1;
            else high = mid - 1;
        }
        return high;
    }

public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int maxi = 0;
        int n = nums1.size();

        for(int i = 0; i < nums1.size(); i++) {
            int j = lowerBound(i, nums2, nums1[i]);
            maxi = max(maxi, j - i);
        }

        return maxi;
    }
};
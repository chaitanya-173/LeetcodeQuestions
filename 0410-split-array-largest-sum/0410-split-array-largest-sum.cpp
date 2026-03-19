class Solution {
private:
    bool isPossible(int pages, vector<int> &arr, int totalStudents) {
        int stu = 1, pagesStudent = 0;
        for(int i=0; i<arr.size(); i++) {
            if(pagesStudent + arr[i] <= pages) {
                pagesStudent += arr[i];
            } else {
                stu++;
                pagesStudent = arr[i];
            }
        }
        return (stu <= totalStudents);
    }
    
public:
    int splitArray(vector<int>& arr, int k) {
        int n = arr.size();
        if(k > n) return -1;
        
        int maxi = *max_element(arr.begin(), arr.end());
        int sum = accumulate(arr.begin(), arr.end(), 0);
        
        int low = maxi, high = sum;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            
            if(isPossible(mid, arr, k)) high = mid - 1;
            else low = mid + 1;
        }
        
        return low;
    }
};
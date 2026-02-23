class Solution {
public:
    int findGCD(vector<int>& nums) {
        int a = INT_MAX;
        int b = INT_MIN;
        for(int i=0; i<nums.size(); i++) {
            a = min(a, nums[i]);
            b = max(b, nums[i]);
        }

        while(a > 0 && b > 0) {
            if(a > b) a = a%b;
            else b = b%a;
        }
        if(a == 0) return b;
        else return a;
    }
};
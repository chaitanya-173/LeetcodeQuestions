class Solution {
public:
    void moveZeroes(vector<int>& a) {
        int n = a.size();
        int j = -1;
        for (int i = 0; i < n; i++) {
            if (a[i] == 0) {
                j = i;
                break;
            }
        }
        // no non-zero elements:
        if (j == -1)
            return;

        for (int i = j + 1; i < n; i++) {
            if (a[i] != 0) {
                swap(a[i], a[j]);
                j++;
            }
        }
    }
};
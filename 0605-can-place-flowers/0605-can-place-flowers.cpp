class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(n == 0) return true;
        int size = flowerbed.size();

        for(int i = 0; i < size; i++) {
            bool left = (i == 0 || flowerbed[i-1] == 0);
            bool right = (i == size-1 || flowerbed[i+1] == 0);

            if(left && right && flowerbed[i] == 0) {
                flowerbed[i] = 1;
                n--;
            }
        }

        return n <= 0;
    }
};
class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int left = 0, right = 0;
        int underscore = 0;

        for(char ch : moves) {
            if(ch == 'L') left++;
            else if(ch == 'R') right++;
            else underscore++;
        }

        return abs(left - right) + underscore;
    }
};
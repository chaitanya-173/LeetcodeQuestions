class Solution {
public:
    bool judgeCircle(string moves) {
        int i = 0, j = 0;
        
        for(char ch : moves) {
            if(ch == 'R') j++;
            else if(ch == 'L') j--;
            else if(ch == 'U') i--;
            else i++;
        }

        return (i == 0 && j == 0);
    }
};
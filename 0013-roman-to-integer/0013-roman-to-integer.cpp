class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mp{{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};

        int sum = 0;
        for(int i=0; i<s.length(); i++) {
            if(s[i] == 'I') {
                if(s[i+1] == 'V') {
                    sum += 4;
                    i+=1;
                    continue;
                }
                if(s[i+1] == 'X') {
                    sum += 9;
                    i+=1;
                    continue;
                }
            }
            if(s[i] == 'X') {
                if(s[i+1] == 'L') {
                    sum += 40;
                    i+=1;
                    continue;
                }
                if(s[i+1] == 'C') {
                    sum += 90;
                    i+=1;
                    continue;
                }
            }
            if(s[i] == 'C') {
                if(s[i+1] == 'D') {
                    sum += 400;
                    i+=1;
                    continue;
                }
                if(s[i+1] == 'M') {
                    sum += 900;
                    i+=1;
                    continue;
                }
            }
             
            sum += mp[s[i]];
        }

        return sum;
    }
};
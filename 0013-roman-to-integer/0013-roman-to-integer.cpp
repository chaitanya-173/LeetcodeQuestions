class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mp{{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};

        int sum = 0;
        for(int i=0; i<s.length(); i++) {
            if( (s[i] == 'I' && (s[i+1] == 'V' || s[i+1] == 'X')) ||
                (s[i] == 'X' && (s[i+1] == 'L' || s[i+1] == 'C')) || 
                (s[i] == 'C' && (s[i+1] == 'D' || s[i+1] == 'M')) ) {
                sum += (mp[s[i+1]] - mp[s[i]]);
                i++;
                continue;
            }
             
            sum += mp[s[i]];
        }

        return sum;
    }
};
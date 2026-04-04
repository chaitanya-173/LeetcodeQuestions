class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n = rows;
        int m = encodedText.size() / rows;

        vector<vector<char>> mat(n, vector<char>(m));

        int ind = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                mat[i][j] = encodedText[ind++];
            }
        }

        string ans = "";
        int prevCol = 0;

        while(prevCol < m) {
            int r = 0, c = prevCol;

            while(r < n && c < m) {
                ans += mat[r][c];
                r++, c++;
            }

            prevCol++;
        }
        
        // remove trailing spaces
        while(!ans.empty() && ans.back() == ' ') {  
            ans.pop_back();
        }

        return ans;
    }
};
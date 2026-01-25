class Solution {
public:
    string getPermutation(int n, int k) {
        // precompute factorials
        vector<int> fact(n, 1);
        for(int i = 1; i < n; i++) fact[i] = fact[i-1] * i;

        // visited array to track used numbers
        vector<bool> vis(n+1, false); // 1-indexed

        string ans = "";
        k--; // convert k to 0-based

        for(int i = 0; i < n; i++) {
            int f = fact[n-1-i];
            int index = k / f; // which unvisited number to pick
            k %= f;

            // find the index of unvisited number
            for(int j = 1; j <= n; j++) {
                if(vis[j]) continue;

                if(index == 0) {
                    ans += to_string(j);
                    vis[j] = true;
                    break;
                }
                index--;
            }
        }

        return ans;
    }
};

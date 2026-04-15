class Solution {
public:
    int maxi = 0;

    void dfs(TreeNode* root, int leftLen, int rightLen) {
        if(!root) return;

        maxi = max({maxi, leftLen, rightLen});

        dfs(root->left, 0, leftLen + 1);  // go left → last move becomes left
        dfs(root->right, rightLen + 1, 0);  // go right → last move becomes right
    }

    int longestZigZag(TreeNode* root) {
        dfs(root, 0, 0);
        return maxi;
    }
};
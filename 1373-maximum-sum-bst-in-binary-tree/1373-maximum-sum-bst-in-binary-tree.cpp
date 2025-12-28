/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans = 0;

    tuple<int,int,int> postorder(TreeNode* root) {
        if(root == NULL) return {INT_MAX, INT_MIN, 0};

        auto [lmin, lmax, lsum] = postorder(root->left);
        auto [rmin, rmax, rsum] = postorder(root->right);

        if(lmax < root->val && root->val < rmin) {
            int currSum = (ans, lsum + rsum + root->val);
            ans = max(ans, currSum);

            return {min(root->val, lmin), max(root->val, rmax), currSum};
        }

        // invalid BST → do NOT propagate child sums
        return {INT_MIN, INT_MAX, 0};
    }

    int maxSumBST(TreeNode* root) {
        postorder(root);
        return ans;
    }
};

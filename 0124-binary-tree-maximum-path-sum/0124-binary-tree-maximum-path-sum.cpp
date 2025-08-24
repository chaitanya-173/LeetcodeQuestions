/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int solve(TreeNode* root, int& maxSum) {
        // base case
        if(root == NULL) return 0;

        // ignore if negative
        int left = max(0, solve(root -> left, maxSum));
        int right = max(0, solve(root -> right, maxSum));

        int currSum = root -> val + left + right;
        maxSum = max(maxSum, currSum);

        return root -> val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {
        int sum = INT_MIN;;
        solve(root, sum);
        return sum;
    }
};
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

    struct NodeInfo {
        bool isBST;
        int minVal;
        int maxVal;
        int sum;
    };

    NodeInfo postorder(TreeNode* root) {
        if(!root) return {true, INT_MAX, INT_MIN, 0};
        
        NodeInfo left = postorder(root->left);
        NodeInfo right = postorder(root->right);

        if(left.isBST && right.isBST &&
            left.maxVal < root->val && root->val < right.minVal) {

            int currSum = left.sum + right.sum + root->val;
            ans = max(ans, currSum);

            return {
                true,
                min(root->val, left.minVal),
                max(root->val, right.maxVal),
                currSum
            };
        }

        return {false, 0, 0, 0};
    }

    int maxSumBST(TreeNode* root) {
        postorder(root);
        return ans;
    }
};

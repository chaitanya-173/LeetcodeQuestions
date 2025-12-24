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
    int maxTime = 0;

    int dfs(TreeNode* root, int start) {
        if(!root) return -1;

        // If current node is the start node
        if(root->val == start) {
            depth(root, 0);   // spread downward
            return 1;
        }

        int left = dfs(root->left, start);
        int right = dfs(root->right, start);

        // If start is in left subtree
        if(left != -1) {
            maxTime = max(maxTime, left);
            depth(root->right, left + 1);
            return left + 1;
        }

        // If start is in right subtree
        if(right != -1) {
            maxTime = max(maxTime, right);
            depth(root->left, right + 1);
            return right + 1;
        }

        return -1;
    }

    void depth(TreeNode* root, int time) {
        if(!root) return;
        maxTime = max(maxTime, time);
        depth(root->left, time + 1);
        depth(root->right, time + 1);
    }

    int amountOfTime(TreeNode* root, int start) {
        dfs(root, start);
        return maxTime;
    }
};

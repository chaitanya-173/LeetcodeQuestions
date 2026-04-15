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
private:
    int solve(TreeNode* root, int maxi) {
        if(!root) return 0;

        int cnt = 0;
        if(root->val >= maxi) {
            cnt++;
            maxi = root->val;
        }

        cnt += solve(root->left, maxi);
        cnt += solve(root->right, maxi);

        return cnt;
    }

public:
    int goodNodes(TreeNode* root) {
        int maxi = INT_MIN;
        return solve(root, maxi);
    }
};
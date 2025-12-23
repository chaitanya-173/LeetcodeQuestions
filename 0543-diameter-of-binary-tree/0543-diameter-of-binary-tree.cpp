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
    int findHeight(TreeNode* root) {
        if(!root) return 0;
        int maxLeft = findHeight(root->left);
        int maxRight = findHeight(root->right);
        return max(maxLeft, maxRight)+1;
    }

    void findMax(TreeNode* node, int& maxi) {
        if(node == NULL) return;

        int lh = findHeight(node->left);
        int rh = findHeight(node->right);

        maxi = max(maxi, lh + rh);

        findMax(node->left, maxi);
        findMax(node->right, maxi);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int dia = 0;
        findMax(root, dia);
        return dia;
    }
};
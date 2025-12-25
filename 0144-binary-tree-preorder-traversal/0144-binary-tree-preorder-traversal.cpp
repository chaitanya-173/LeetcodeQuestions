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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) return ans;
        TreeNode* cur = root;

        while(cur != NULL) {
            // simple inorder
            if(cur->left == NULL) {
                ans.push_back(cur->val);
                cur = cur->right;
            } else {
                // if left node is present then find the right most node of the left node(prev)
                TreeNode* prev = cur->left;
                while(prev->right && prev->right != cur) {
                    prev = prev->right;
                }

                // 1st step: if found out the prev then connect it to the cur and move left
                // main traversal toh yahin hora hai.. yahin hum left jaare hain aur print bhi krre hain
                if(prev->right == NULL) {
                    prev->right = cur;
                    ans.push_back(cur->val);
                    cur = cur->left;
                }
                // prev->right == cur
                else {  // if the thread already exists then cut it off and move right
                    prev->right = NULL;
                    cur = cur->right;
                }
            }
        }

        return ans;
    }
};
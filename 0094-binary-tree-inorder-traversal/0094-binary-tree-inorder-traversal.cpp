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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode* node = root;

        while(node != NULL || !st.empty()) {
            // left chain mein jaate raho
            while(node != NULL) {
                st.push(node);
                node = node->left;
            }

            // ab process karo
            node = st.top();
            st.pop();
            ans.push_back(node->val);

            // right subtree
            node = node->right;
        }

        return ans;
    }
};
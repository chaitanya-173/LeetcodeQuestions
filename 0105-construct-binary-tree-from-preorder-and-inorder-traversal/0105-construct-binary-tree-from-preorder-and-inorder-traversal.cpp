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
    void build(TreeNode* &root, int preStart, int preEnd, int inStart, int inEnd, 
                    vector<int> &preorder, vector<int> &inorder, unordered_map<int,int> &hash) {
        if(preStart > preEnd || inStart > inEnd) {
            root = NULL;
            return;
        }

        root = new TreeNode(preorder[preStart]);

        int inRoot = hash[root->val];
        int numsLeft = inRoot - inStart;

        build(root->left, preStart+1, preStart+numsLeft, inStart, inRoot-1, preorder, inorder, hash);
        build(root->right, preStart+numsLeft+1, preEnd, inRoot+1, inEnd, preorder, inorder, hash);
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> hash;
        for(int i=0; i<inorder.size(); i++) {
            hash[inorder[i]] = i;
        }

        TreeNode* root = NULL;
        build(root, 0, preorder.size()-1, 0, inorder.size()-1, preorder, inorder, hash);

        return root;
    }
};
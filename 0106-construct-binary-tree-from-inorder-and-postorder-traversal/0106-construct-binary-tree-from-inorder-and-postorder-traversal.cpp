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
    TreeNode* build(int inStart, int inEnd, int postStart, int postEnd,     
                    vector<int> &inorder, vector<int> &postorder, unordered_map<int,int> &hash) {
        if(inStart > inEnd || postStart > postEnd) return NULL;

        TreeNode* root = new TreeNode(postorder[postEnd]);

        int inRoot = hash[root->val];
        int numsLeft = inRoot - inStart;

        root->left = build(inStart, inRoot-1, postStart, postStart+numsLeft-1, inorder, postorder, hash);
        root->right = build(inRoot+1, inEnd, postStart+numsLeft, postEnd-1, inorder, postorder, hash);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> hash;
        for(int i=0; i<inorder.size(); i++) {
            hash[inorder[i]] = i;
        }

        TreeNode* root = build(0, inorder.size()-1, 0, postorder.size()-1, inorder, postorder, hash);

        return root;
    }
};
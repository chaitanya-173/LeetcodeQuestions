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
class BSTIterator {
private:
    stack<TreeNode*> st1, st2;

    void pushAllLeft(TreeNode* root) {
        while(root != NULL) {
            st1.push(root);
            root = root->left;
        }
    }

    void pushAllRight(TreeNode* root) {
        while(root != NULL) {
            st2.push(root);
            root = root->right;
        }
    }

public:
    BSTIterator(TreeNode* root) {
        pushAllLeft(root);
        pushAllRight(root);
    }

    int next() {
        TreeNode* topNode = st1.top();
        st1.pop();
        pushAllLeft(topNode->right);
        return topNode->val;
    }

    int previous() {
        TreeNode* topNode = st2.top();
        st2.pop();
        pushAllRight(topNode->left);
        return topNode->val;
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BSTIterator bst(root);
        int i = bst.next();
        int j = bst.previous();

        while(i < j) {
            if(i + j < k) i = bst.next();
            else if(i + j > k) j = bst.previous();
            else return true; 
        }

        return false;
    }
};
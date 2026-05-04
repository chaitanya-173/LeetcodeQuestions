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
    TreeNode* makeBST(int low, int high, vector<int> &nums) {
        if(low > high) return NULL;

        int mid = low + (high - low) / 2;

        TreeNode* node = new TreeNode(nums[mid]);
        
        node->left = makeBST(low, mid-1, nums);
        node->right = makeBST(mid+1, high, nums);

        return node;
    }

public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return makeBST(0, nums.size()-1, nums);
    }
};
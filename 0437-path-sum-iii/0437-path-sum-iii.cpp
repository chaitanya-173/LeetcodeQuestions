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
    int solve(TreeNode* root, long long sum, int targetSum, unordered_map<long long,int> &preSum) {
        if(!root) return 0;

        sum += root->val;
        
        int cnt = 0;
        if(preSum.count(sum - targetSum)) cnt += preSum[sum - targetSum];
        preSum[sum]++;

        cnt += solve(root->left, sum, targetSum, preSum);
        cnt += solve(root->right, sum, targetSum, preSum);

        preSum[sum]--;

        return cnt;
    }

public:
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long,int> preSum;
        preSum[0] = 1;
        return solve(root, 0, targetSum, preSum);
    }
};
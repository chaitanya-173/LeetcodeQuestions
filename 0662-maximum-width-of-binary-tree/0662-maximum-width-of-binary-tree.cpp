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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        queue<pair<TreeNode*, long long>> q;  // node, index
        q.emplace(root, 0);
        int maxWidth = 0;

        while(!q.empty()) {
            int size = q.size();
            long long mmin = q.front().second;
            long long firstIndex, lastIndex;
            for(int i=0; i<size; i++) {
                auto [node, index] =  q.front();
                q.pop();
                long long currIndex = index - mmin;

                if(i == 0) firstIndex = currIndex;
                if(i == size-1) lastIndex = currIndex;

                if(node->left) q.emplace(node->left, currIndex*2 + 1);
                if(node->right) q.emplace(node->right, currIndex*2 + 2);
            }
            maxWidth = max(maxWidth, static_cast<int>(lastIndex - firstIndex + 1));
        }

        return maxWidth;
    }
};
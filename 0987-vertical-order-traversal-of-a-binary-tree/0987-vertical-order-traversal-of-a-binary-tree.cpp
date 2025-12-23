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
    void dfs(TreeNode* node, int row, int col, vector<tuple<int,int,int>> &nodes) {
        if(node == NULL) return;
        nodes.emplace_back(col, row, node->val);
        dfs(node->left, row+1, col-1, nodes);
        dfs(node->right, row+1, col+1, nodes);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<tuple<int,int,int>> nodes;  // col, row, val
        dfs(root, 0, 0, nodes); 

        sort(nodes.begin(), nodes.end());

        vector<vector<int>> ans;
        int prevCol = INT_MIN;

        for(auto it: nodes) {
            auto [col, row, val] = it;
            if(col != prevCol) {  // jaise hi column change hota hai, ek naya vertical column start karo, ans mein ek empty vector daal do
                ans.push_back({});
                prevCol = col;
            }
            ans.back().push_back(val); // last inserted column mein value daal do
        }

        return ans;
    }
};
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
    int amountOfTime(TreeNode* root, int start) {
        // parent mapping
        unordered_map<TreeNode*, TreeNode*> parent;
        queue<TreeNode*> q;
        q.push(root);

        TreeNode* startNode = NULL;

        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if(node->val == start) startNode = node;

            if(node->left) {
                q.push(node->left);
                parent[node->left] = node;
            }
            if(node->right) {
                q.push(node->right);
                parent[node->right] = node;
            }
        }

        unordered_set<TreeNode*> vis;
        queue<TreeNode*> qq;
        qq.push(startNode);
        vis.insert(startNode);

        int time = -1;

        while(!qq.empty()) {
            int size = qq.size();

            for(int i=0; i<size; i++) {
                TreeNode* node = qq.front();
                qq.pop();

                // left
                if(node->left && !vis.count(node->left)) {
                    qq.push(node->left);
                    vis.insert(node->left);
                }
                
                // right
                if(node->right && !vis.count(node->right)) {
                    qq.push(node->right);
                    vis.insert(node->right);
                }

                // parent
                if(parent.count(node) && !vis.count(parent[node])) {
                    qq.push(parent[node]);
                    vis.insert(parent[node]);
                }
            }
            time++;
        }

        return time;
    }
};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;
        queue<TreeNode*> q;
        q.push(root);

        // parent mapping
        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if(node->left) {
                q.push(node->left);
                parent[node->left] = node;
            }
            if(node->right) {
                q.push(node->right);
                parent[node->right] = node;
            }
        }

        // bfs
        unordered_set<TreeNode*> vis;
        queue<TreeNode*> qq;
        qq.push(target);
        vis.insert(target);

        int dist = 0;
        while(!qq.empty()) {
            int size = qq.size();

            if(dist == k) {
                vector<int> ans;
                while(!qq.empty()) {
                    ans.push_back(qq.front()->val);
                    qq.pop();
                }
                return ans;
            }

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
            dist++;
        }

        return {};
    }
};
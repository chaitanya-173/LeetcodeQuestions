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

        // 1) parent mapping
        unordered_map<TreeNode*, TreeNode*> parent;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if(node->left) {
                parent[node->left] = node;
                q.push(node->left);
            }
            if(node->right) {
                parent[node->right] = node;
                q.push(node->right);
            }
        }

        // 2) BFS from target
        unordered_set<TreeNode*> vis;
        queue<TreeNode*> bfs;
        bfs.push(target);
        vis.insert(target);

        int dist = 0;

        while(!bfs.empty()) {
            int size = bfs.size();

            if(dist == k) {
                vector<int> ans;
                while(!bfs.empty()) {
                    ans.push_back(bfs.front()->val);
                    bfs.pop();
                }
                return ans;
            }

            for(int i=0; i<size; i++) {
                TreeNode* node = bfs.front();
                bfs.pop();

                // left
                if(node->left && !vis.count(node->left)) {
                    vis.insert(node->left);
                    bfs.push(node->left);
                }

                // right
                if(node->right && !vis.count(node->right)) {
                    vis.insert(node->right);
                    bfs.push(node->right);
                }

                // parent
                if(parent.count(node) && !vis.count(parent[node])) {
                    vis.insert(parent[node]);
                    bfs.push(parent[node]);
                }
            }
            dist++;
        }

        return {};
    }
};



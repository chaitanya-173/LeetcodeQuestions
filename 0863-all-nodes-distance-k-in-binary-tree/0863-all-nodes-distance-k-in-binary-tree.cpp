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

        // graph: node -> neighbours
        unordered_map<TreeNode*, vector<TreeNode*>> graph;
        queue<TreeNode*> q;
        q.push(root);

        // build undirected graph
        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if(node->left) {
                graph[node].push_back(node->left);
                graph[node->left].push_back(node);
                q.push(node->left);
            }
            if(node->right) {
                graph[node].push_back(node->right);
                graph[node->right].push_back(node);
                q.push(node->right);
            }
        }

        // BFS from target
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

                for(auto nei : graph[node]) {
                    if(!vis.count(nei)) {
                        vis.insert(nei);
                        bfs.push(nei);
                    }
                }
            }
            dist++;
        }

        return {};
    }
};


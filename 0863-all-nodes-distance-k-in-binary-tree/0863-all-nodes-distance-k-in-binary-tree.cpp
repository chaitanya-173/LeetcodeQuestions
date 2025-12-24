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
        map<int, vector<int>> mp;
        queue<TreeNode*> q;
        q.push(root);

        // build graph
        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if(node->left) {
                q.push(node->left);
                mp[node->val].push_back(node->left->val);
                mp[node->left->val].push_back(node->val);
            }
            if(node->right) {
                q.push(node->right);
                mp[node->val].push_back(node->right->val);
                mp[node->right->val].push_back(node->val);
            }
        }

        // BFS from target
        vector<int> ans;
        unordered_set<int> vis;
        queue<int> bfs;

        bfs.push(target->val);
        vis.insert(target->val);

        int dist = 0;

        while(!bfs.empty()) {
            int size = bfs.size();

            if(dist == k) {
                while(!bfs.empty()) {
                    ans.push_back(bfs.front());
                    bfs.pop();
                }
                return ans;
            }

            for(int i = 0; i < size; i++) {
                int node = bfs.front();
                bfs.pop();

                for(auto it : mp[node]) {
                    if(!vis.count(it)) {
                        vis.insert(it);
                        bfs.push(it);
                    }
                }
            }
            dist++;
        }

        return ans;
    }
};

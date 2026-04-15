class Node {
    Node* links[2];
public:
    bool containsKey(int bit) {
        return links[bit] != NULL;
    }
    
    void put(int bit, Node* node) {
        links[bit] = node;
    }
    
    Node* get(int bit) {
        return links[bit];
    }
};

class Trie {
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(int num) {
        Node* node = root;
        for(int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if(!node->containsKey(bit)) {
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }
    
    int getMax(int num) {
        Node* node = root;
        int maxNum = 0;
        for(int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if(node->containsKey(!bit)) {
                maxNum = maxNum | (1 << i);
                node = node->get(!bit);
            } else {
                node = node->get(bit);
            }
        }
        return maxNum;
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(), nums.end());

        vector<tuple<int,int,int>> offQ;
        int q = queries.size();

        for(int i = 0; i < q; i++) {
            offQ.push_back({queries[i][1], queries[i][0], i});
        }

        sort(offQ.begin(), offQ.end());

        vector<int> ans(q, 0);
        int n = nums.size();
        int ind = 0;
        Trie t;

        for(auto &it : offQ) {
            auto [ai, xi, qInd] = it;

            while(ind < n && nums[ind] <= ai) {
                t.insert(nums[ind]);
                ind++;
            }

            if(ind != 0) ans[qInd] = t.getMax(xi);
            else ans[qInd] = -1;
        }

        return ans;
    }
};
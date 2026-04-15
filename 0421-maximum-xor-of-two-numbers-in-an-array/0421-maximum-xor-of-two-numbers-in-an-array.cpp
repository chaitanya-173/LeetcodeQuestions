class Node {
private:
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
private:
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
    int findMaximumXOR(vector<int>& nums) {
        Trie t;

        for(int i = 0; i < nums.size(); i++) {
            t.insert(nums[i]);
        }
        
        int maxi = 0;
        for(int i = 0; i < nums.size(); i++) {
            maxi = max(maxi, t.getMax(nums[i]));
        }
        
        return maxi;
    }
};

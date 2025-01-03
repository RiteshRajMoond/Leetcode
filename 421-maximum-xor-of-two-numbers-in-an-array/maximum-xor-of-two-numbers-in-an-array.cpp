class Node {
private:
    Node* links[2];
public:
    Node() {
        links[0] = NULL;
        links[1] = NULL;
    }

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

    int get_max_xor(int num) {
        int res = 0;
        Node* node = root;
        for(int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if(node->containsKey(!bit)) {
                res |= (1 << i);
                node = node->get(!bit);
            } else {
                node = node->get(bit);
            }
        }
        return res;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();
        Trie t;
        for(int i = 0; i < n; i++) {
            t.insert(nums[i]);
        }

        int res = 0;
        for(int i = 0; i < n; i++) {
            res = max(t.get_max_xor(nums[i]), res);
        }
        return res;
    }
};
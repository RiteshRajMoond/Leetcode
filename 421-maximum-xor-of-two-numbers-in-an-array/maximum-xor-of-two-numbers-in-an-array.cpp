class Node {
private:
    Node* links[2];
public:
    Node() {
        links[0] = nullptr;
        links[1] = nullptr;
    }

    void put(int bit, Node* node) {
        links[bit] = node;
    }

    Node* get(int bit) {
        return links[bit];
    }

    bool containsKey(int bit) {
        return links[bit] != nullptr;
    }
};

class Trie {
private:
    Node* root;
public:
    Trie() {
        root = new Node();
    }

    void insert_in_trie(int num) {
        Node* cur = root;
        for(int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if(!cur->containsKey(bit)) cur->put(bit, new Node());
            cur = cur->get(bit);
        }
    }

    int get_max_xor(int num) {
        Node* cur = root;
        int res = 0;
        for(int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if(cur->containsKey(!bit)) {
                // set ith bit
                res |= 1 << i;
                cur = cur->get(!bit);
            } else {
                cur = cur->get(bit);
            }
        }
        return res;
    }

private:
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie t;
        for(int & i : nums) t.insert_in_trie(i);

        int res = 0;
        for(int i = 0; i < nums.size(); i++) {
            res = max(res, t.get_max_xor(nums[i]));
        }

        return res;
    }
};
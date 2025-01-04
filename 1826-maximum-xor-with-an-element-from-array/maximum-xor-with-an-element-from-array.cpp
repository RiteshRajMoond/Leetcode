class Node{
    Node* links[2];
public:
    Node() {
        links[0] = nullptr;
        links[1] = nullptr;
    }

    bool containsKey(int bit) {
        return links[bit] != nullptr;
    }

    void put(int bit, Node* node) {
        links[bit] = node;
    }

    Node* get(int bit) {
        return links[bit];
    }
};

class Trie{
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
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(), nums.end());
        vector<tuple<int, int, int>> q; // mi, xi, index
        for(int i = 0; i < queries.size(); i++) {
            q.push_back({queries[i][1], queries[i][0], i});
        }
        sort(q.begin(), q.end()); // sort by mi

        vector<int> res(queries.size());
        int ind = 0;
        Trie t;
        for(auto& i : q) {
            int mi = get<0> (i);
            int xi = get<1> (i);
            int idx = get<2> (i);
            while(ind < nums.size() && nums[ind] <= mi) {
                t.insert(nums[ind]);
                ind++;
            }

            if(ind == 0) res[idx] = -1;
            else res[idx] = t.get_max_xor(xi);
        }
        return res;
    }
}; 
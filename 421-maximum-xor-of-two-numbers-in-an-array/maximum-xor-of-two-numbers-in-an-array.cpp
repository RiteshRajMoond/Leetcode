class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int max_xor = 0, mask = 0;
        for (int i = 31; i >= 0; --i) {
            mask |= (1 << i);
            unordered_set<int> prefix_set;
            for (int num : nums) {
                prefix_set.insert(num & mask);
            }
            int new_xor = max_xor | (1 << i);
            for (int prefix : prefix_set) {
                if (prefix_set.count(new_xor ^ prefix)) {
                    max_xor = new_xor;
                    break;
                }
            }
        }
        return max_xor;
    }
};
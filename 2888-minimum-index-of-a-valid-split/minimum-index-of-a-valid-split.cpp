class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int, int> freq;

        int max_freq = 0, num = -1;
        for(int& i : nums) {
            freq[i]++;
            if(freq[i] > max_freq) {
                max_freq = freq[i];
                num = i;
            }
        }

        int cnt1 = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == num) cnt1++;

            // check if dominant in both
            int size1 = i+1, size2 = nums.size()-i-1;
            int cnt2 = max_freq-cnt1;
            if(size1 < 2*cnt1 && size2 < 2*cnt2) return i;
        }

        return -1;
    }
};
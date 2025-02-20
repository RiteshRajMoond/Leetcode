class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string diff_binary;

        int n = nums.size();
        for(int i = 0; i < n; i++) {
            diff_binary += nums[i][i] == '1' ? '0' : '1';
        }
        return diff_binary;
    }
};
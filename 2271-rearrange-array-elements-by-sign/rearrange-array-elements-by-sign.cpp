class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);

        int i = 0, j = 1;
        for(int num : nums) {
            if(num >= 0) {
                res[i] = num;
                i+=2;
            } else {
                res[j] = num;
                j+=2;
            }
        }
        return res;
    }
};
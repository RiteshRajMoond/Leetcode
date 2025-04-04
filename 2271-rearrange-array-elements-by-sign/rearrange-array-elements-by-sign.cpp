class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        queue<int> pos, neg;
        int n = nums.size();

        for(int& num : nums) {
            if(num >= 0) pos.push(num);
            else neg.push(num);
        }

        bool flag = true;

        for(int i = 0; i < n; i++) {
            if(flag) {
                nums[i] = pos.front();
                pos.pop();
            } else {
                nums[i] = neg.front();
                neg.pop();
            }
            flag = !flag;
        }

        return nums;
    }
};
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> dq;

        for(int i = 0; i < nums.size(); i++) {
            // remove elements if they are out of index
            if(!dq.empty() && dq.front() < i - k + 1) dq.pop_front();

            // remove the elements from the back which are smaller than the current number
            while(!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();

            // push the current element
            dq.push_back(i);

            if(i >= k-1) res.push_back(nums[dq.front()]);
        }
        return res;
    }
};
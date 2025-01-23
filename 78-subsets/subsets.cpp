class Solution {
public:
    set<vector<int>> st;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        f(nums, 0, temp);

        vector<vector<int>> res;
        for(auto& i : st) {
            res.push_back(i);
        }
        return res;
    }
private:
    void f(vector<int>& nums, int idx, vector<int> temp) {
        if(idx == nums.size()) {
            sort(temp.begin(), temp.end());
            st.insert(temp);
            return;
        }

        f(nums, idx+1, temp);
        
        temp.push_back(nums[idx]);
        f(nums, idx+1, temp);
        temp.pop_back();
    }
};
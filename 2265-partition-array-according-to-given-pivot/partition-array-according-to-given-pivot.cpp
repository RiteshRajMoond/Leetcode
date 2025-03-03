class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> before, after;
        int cnt = 0;

        for(int& i : nums) {
            if(i == pivot) cnt++;
            else if(i > pivot) after.push_back(i);
            else before.push_back(i);
        }

        vector<int> res;
        for(int& i : before) res.push_back(i);
        while(cnt--) res.push_back(pivot);
        for(int& i : after) res.push_back(i);

        return res;
    }
};
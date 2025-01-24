class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        f(candidates, target, 0, temp);
        return res;
    }
private:
    void f(vector<int>& arr, int k, int idx, vector<int>& temp) {
        // base case
        if(k < 0) return;
        if(k == 0) {
            res.push_back(temp);
            return;
        }

        for(int i = idx; i < arr.size(); i++) {
            if(i > idx && arr[i] == arr[i-1]) continue;
            temp.push_back(arr[i]);
            f(arr, k-arr[i], i+1, temp);
            temp.pop_back();
        }
    }
};
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> path;
        backtrack(candidates, 0, 0, target, path);
        return res;
    }
private:
    void backtrack(vector<int>& arr, int idx, int sum, int target, vector<int>& path) {
        if(sum == target) {
            res.push_back(path);
            return;
        } 
        if(sum > target || idx >= arr.size()) return;

        path.push_back(arr[idx]);
        backtrack(arr, idx, sum+arr[idx], target, path);
        path.pop_back();

        backtrack(arr, idx+1, sum, target, path);
    }
};
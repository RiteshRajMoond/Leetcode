class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        // code here
        int i = 0, j = 0;
        int n = arr.size();
        int sum = 0;
        while(j < n) {
            sum += arr[j];
            if(sum == target) {
                return {i+1, j+1};
            } else if(sum > target) {
                while(sum > target && i < j) {
                    sum -= arr[i];
                    i++;
                }
                if(sum == target) return {i+1, j+1};
            }
            j++;
        }
        
        if(sum == target) return {i+1, j+1};
        
        return {-1};
    }
};
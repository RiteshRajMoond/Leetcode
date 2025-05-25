class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        // Your code here
        int sum = INT_MIN, cur = 0;
        
        for(int& i : arr) {
            cur += i;
            sum = max(cur, sum);
            if(cur < 0) cur = 0;
        }
        
        return sum;
    }
};
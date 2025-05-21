class Solution {
    
    vector<int> dp;
    
    int f(int cur, int n) {
        if(cur == n) return 0;
        if (cur > n) return 1e8;
        
        if(dp[cur] != -1) return dp[cur];
        
        int add = f(cur+1, n)+1;
        int mul = 1e8;
        if(cur != 0) mul = f(cur*2, n) + 1;
        
        return dp[cur] = min(add, mul);
    }
  public:
    int minOperation(int n) {
        // code here.
        dp.resize(n, -1);
        return f(0, n);
    }
};
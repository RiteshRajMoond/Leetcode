//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    
    vector<vector<int>> dp;
    
    int drops(int n, int k) {
        if(n == 1) return k;
        if(k == 0 || k == 1) return k;
        
        if(dp[n][k] != -1) return dp[n][k];
        
        int min_drops = INT_MAX;
        
        for(int i = 1; i <= k; i++) {
            int broke = drops(n-1, i-1);
            int not_broke = drops(n, k-i);
            
            min_drops = min(min_drops, max(broke, not_broke)+1);
        }
        
        return dp[n][k] = min_drops;
    }
  public:
    // Function to find minimum number of attempts needed in
    // order to find the critical floor.
    int eggDrop(int n, int k) {
        // your code here
        dp = vector<vector<int>> (n+1, vector<int> (k+1, -1));
        return drops(n, k);
    }
};


//{ Driver Code Starts.
int main() {
    // taking total testcases
    int t;
    cin >> t;
    while (t--) {
        // taking eggs and floors count
        int n, k;
        cin >> n >> k;
        Solution ob;
        // calling function eggDrop()
        cout << ob.eggDrop(n, k) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// Function to return minimum number of jumps to end of array

class Solution {
  public:
    int minJumps(vector<int>& arr) {
        // code here
        if(arr[0] == 0) return -1;
        int n = arr.size();
        if(n == 1) return 0;
        int low = 0, high = 0;
        int jumps = 0;
        
        while(high < n-1) {
            int far = 0;
            for(int i = low; i <= high; i++)
                far = max(far, i + arr[i]);
            if(far == high) return -1;
            low = high+1;
            high = far;
            jumps++;
        }
        
        return jumps;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, i, j;
        vector<int> arr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.minJumps(arr) << endl << "~\n";
    }
    return 0;
}

// } Driver Code Ends
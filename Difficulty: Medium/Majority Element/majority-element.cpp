//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    int majorityElement(vector<int>& arr) {
        // your code here
        int n = arr.size();
        int el = -1, freq = 0;
        
        for(int & i : arr) {
            if(freq == 0) {
                el = i;
                freq++;
            } else if(i == el) ++freq;
            else freq--;
        }
        
        int cnt = 0;
        for(int& i : arr) if(i == el) cnt++;
        
        if(cnt > n/2) return el;
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n;
        vector<int> a, b;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.majorityElement(a) << endl;
    }

    return 0;
}

// } Driver Code Ends
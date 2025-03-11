//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    bool is_pair(const char& a, const char& b) {
        if(a == '(' && b == ')') return true;
        else if(a == '{' && b == '}') return true;
        else if(a == '[' && b == ']') return true;
        return false;
    }
  public:
    bool isBalanced(string& s) {
        // code here
        stack<char> st;
        for(char& c : s) {
            if(c == '(' || c == '{' || c == '[') st.push(c);
            else if(!st.empty() && is_pair(st.top(), c)) st.pop();
            else st.push(c);
        }
        
        return st.empty();
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    string a;
    cin >> t;
    while (t--) {
        cin >> a;
        Solution obj;
        if (obj.isBalanced(a))
            cout << "true" << endl;
        else
            cout << "false" << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends
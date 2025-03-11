//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    int merge(vector<int>& arr, int l, int mid, int r) {
        int i = l, j = mid+1;
        int cnt = 0;
        vector<int> sorted;
        
        while(i <= mid && j <= r) {
            if(arr[i] <= arr[j]) {
                sorted.push_back(arr[i]);
                i++;
            } else {
                cnt += mid-i+1;
                sorted.push_back(arr[j]);
                j++;
            }
        }
        
        while(i <= mid) sorted.push_back(arr[i++]);
        while(j <= r) sorted.push_back(arr[j++]);
        
        for(int k = 0; k < sorted.size(); k++) {
            arr[l + k] = sorted[k];
        }
        
        return cnt;
    }
    
    int merge_sort(vector<int>& arr, int l, int r) {
        int cnt = 0;
        if(l < r) {
            int mid = l + (r-l)/2;
            cnt += merge_sort(arr, l, mid);
            cnt += merge_sort(arr, mid+1, r);
            cnt += merge(arr, l, mid, r);
        }
        return cnt;
    }
  public:
    // Function to count inversions in the array.
    int inversionCount(vector<int> &arr) {
        // Your Code Here
        return merge_sort(arr, 0, arr.size()-1);
    }
};


//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n;
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);
        Solution obj;
        cout << obj.inversionCount(a) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends
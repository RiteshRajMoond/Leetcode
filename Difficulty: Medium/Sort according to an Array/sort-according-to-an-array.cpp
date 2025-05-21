// User function template in C++

class Solution {
  public:
    // A1[] : the input array-1
    // N : size of the array A1[]
    // A2[] : the input array-2
    // M : size of the array A2[]

    // Function to sort an array according to the other array.
    vector<int> sortA1ByA2(vector<int> A1, int N, vector<int> A2, int M) {
        // Your code her
        map<int, int> mp;
        for(int& i : A1) {
            mp[i]++;
        }
        
        vector<int> res;
        for(int& i : A2) {
            int freq = mp[i];
            for(int j = 0; j < freq; j++) res.push_back(i);
            mp[i] = 0;
        }
        
        for(auto& it : mp) {
            int el = it.first;
            int freq = it.second;
            
            for(int i = 0; i < freq; i++) {
                res.push_back(el);
            }
        }
        return res;
    }
};
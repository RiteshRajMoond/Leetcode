class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> res(n);
        unordered_map<int, int> mp1;
        unordered_map<int, int> mp2;

        for(int i = 0; i < n; i++) {
            mp1[A[i]]++;
            mp2[B[i]]++;

            int cnt = 0;
            for(auto& [f, s]:mp1) {
                if(mp2[f] == s) cnt += s;
            }

            res[i] = cnt;
        }
        
        return res;
    }
};
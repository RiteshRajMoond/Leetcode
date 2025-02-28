class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        vector<int> cur(m+1, 0), nxt(m+1, 0);

        for(int i = n-1; i >= 0; i--) {
            for(int j = m-1; j >= 0; j--) {
                if(text1[i] == text2[j]) 
                    cur[j] = 1 + nxt[j+1];
                else 
                    cur[j] = max(nxt[j], cur[j+1]);
            }
            nxt = cur;
        }
        return cur[0];
    }

};
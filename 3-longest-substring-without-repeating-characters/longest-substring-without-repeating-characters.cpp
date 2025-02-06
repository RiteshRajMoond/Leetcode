class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_set<int> st;
        int i = 0, j = 0, res = 0;
        while(j < n) {
            if(!st.count(s[j])) {
                st.insert(s[j]);
                j++;
                res = max(res, j-i);
            } else {
                st.erase(s[i]);
                i++;
            }
        }
        return res;
    }
};
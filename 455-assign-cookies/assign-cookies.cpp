class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int children = g.size(), cookies = s.size();
        int satisfied_children = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int i = 0, j = 0;
        while(i < children && j < cookies) {
            if(s[j] >= g[i]) {
                satisfied_children++;
                j++;
                i++;
            } else {
                j++;
            }
        }

        return satisfied_children;
    }
};
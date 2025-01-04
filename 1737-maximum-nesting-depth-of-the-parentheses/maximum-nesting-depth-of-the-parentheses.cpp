class Solution {
public:
    int maxDepth(string s) {
        int res = 0, cur = 0;
        for(char& ch : s) {
            if(ch == '(') {
                cur++;
                res = max(cur, res);
            } else if(ch == ')') {
                cur--;
            }
        }
        return res;
    }
};
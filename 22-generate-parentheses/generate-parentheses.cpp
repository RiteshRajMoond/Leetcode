class Solution {
public:
    vector<string> res;
    vector<string> generateParenthesis(int n) {
        f(n, 0, 0, "");
        return res;
    }
private:
    void f(int n, int sb1, int sb2, string temp) {
        if(sb1 > n || sb2 > n) return;
        if(sb1 == sb2 && sb1 + sb2 == 2*n) {
            res.push_back(temp);
            return;
        }

        f(n, sb1 + 1, sb2, temp + "(");
        if(sb1 > sb2) f(n, sb1, sb2+1, temp+")");
    }
};
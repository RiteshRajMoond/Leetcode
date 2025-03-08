class Solution {
public:
    int minAddToMakeValid(string s) {
        int opn = 0, cls = 0;
        for(char& c : s) {
            if(c == '(') opn++;
            else {
                if(opn) opn--;
                else cls++;
            }
        }

        return cls + opn;
    }
};
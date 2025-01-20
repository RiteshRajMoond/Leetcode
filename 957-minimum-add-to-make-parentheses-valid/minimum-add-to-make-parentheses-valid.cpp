class Solution {
public:
    int minAddToMakeValid(string s) {
        int cnt = 0, rem = 0;
        for(char& c : s) {
            if(c == '(') cnt++;
            else {
                if(cnt) cnt--;
                else rem++;
            }
        }
        return cnt + rem;
    }
};
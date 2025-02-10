class Solution {
public:
    string clearDigits(string s) {
        stack<char> st;
        for(char& ch : s) {
            if(ch >= 'a' && ch <= 'z') st.push(ch);
            else {
                st.pop();
            }
        }

        string cleared_string = "";
        while(!st.empty()) {
            cleared_string += st.top();
            st.pop();
        }

        reverse(cleared_string.begin(), cleared_string.end());
        return cleared_string;
    }
};
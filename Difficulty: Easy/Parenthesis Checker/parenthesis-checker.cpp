
class Solution {
  public:
    bool is_match(char c1, char c2) {
        if(c1 == '(' && c2 == ')' || c1 == '{' && c2 == '}' || c1 == '[' && c2 == ']')
            return true;
        return false;
    }
  
    bool isBalanced(string& s) {
        // code here
        stack<char> st;
        
        for(char& c : s) {
            if(c == '(' || c == '{' || c == '[') st.push(c);
            else if(!st.empty() && is_match(st.top(), c)) st.pop();
            else return false;
        }
        
        return st.empty();
    }
};
class Solution {
  public:
    vector<string> res;
    
    void gen_pem(string& s, int idx) {
        if(s.size() == idx) {
            res.push_back(s);
            return;
        }
        
        unordered_set<char> st;
        
        for(int i = idx; i < s.size(); i++) {
            if(st.count(s[i])) continue;
            st.insert(s[i]);
            swap(s[i], s[idx]);
            gen_pem(s, idx+1);
            swap(s[i], s[idx]);
        }
    }
    
    vector<string> findPermutation(string &s) {
        // Code here there
        gen_pem(s, 0);
        return res;
    }
};

class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        vector<string> w;
        while(ss >> s) {
            w.push_back(s);
        }
        string res = "";
        for(auto i=w.rbegin(); i!=w.rend(); i++){
            if(!res.empty()) res += " ";
            res += *i;
        }
        return res;
    }
};
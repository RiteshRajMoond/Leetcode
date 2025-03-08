class Solution {
    string into_rle(string s) {
        string encoded = "";
        for(int i = 0; i < s.size(); i++) {
            int freq = 1;
            while(i < s.size()-1 && s[i] == s[i+1]) {
                freq++;
                i++;
            }
            encoded += to_string(freq) + s[i];
        }
        return encoded;
    }
public:
    string countAndSay(int n) {
        if(n == 1) return "1";

        string prev = countAndSay(n-1);
        string cur = into_rle(prev);
        return cur;
    }
};
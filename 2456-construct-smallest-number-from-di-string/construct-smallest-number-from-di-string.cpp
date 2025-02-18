class Solution {
    bitset<10> vis;
    string small;

    void f(const string& pattern, string cur, int idx) {
        if(cur.size() == pattern.size()+1) {
            small = min(small, cur);
            return;
        }

        for(char ch = '1'; ch <= '9'; ch++) {
            if(vis[ch - '0']) continue;
            vis[ch - '0'] = 1;
            if(pattern[idx] == 'I' && cur.back() < ch) {
                f(pattern, cur + ch, idx+1);
            } else if(pattern[idx] == 'D' && cur.back() > ch) {
                f(pattern, cur+ch, idx+1);
            }
            vis[ch - '0'] = 0;
        }
    }
public:
    string smallestNumber(string pattern) {
        small = "999999999";

        for(char a = '1'; a <= '9'; a++) {
            vis[a - '0'] = 1;
            f(pattern, string(1, a), 0);
            vis[a - '0'] = 0;
        }

        return small;
    }
};
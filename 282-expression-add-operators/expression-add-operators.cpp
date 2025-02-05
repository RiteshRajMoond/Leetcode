class Solution {
    vector<string> res;

    void add_ops(string num, int target, long cur, long prev, int idx, string path) {
        if(idx == num.size()) {
            if(cur == target) res.push_back(path);
            return;
        }

        for (int i = idx; i < num.size(); i++) {
            if (i > idx && num[idx] == '0') break; // Prevent numbers with leading zeros

            string part = num.substr(idx, i - idx + 1);
            long nm = stol(part);

            if (idx == 0) {
                add_ops(num, target, nm, nm, i + 1, path + part);
            } else {
                add_ops(num, target, cur + nm, nm, i + 1, path + "+" + part);
                add_ops(num, target, cur - nm, -nm, i + 1, path + "-" + part);
                add_ops(num, target, cur - prev + (prev * nm), prev * nm, i + 1, path + "*" + part);
            }
        }
        
    }
public:
    vector<string> addOperators(string num, int target) {
        add_ops(num, target, 0, 0, 0, "");
        return res;
    }
};
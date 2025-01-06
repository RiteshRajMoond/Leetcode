class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> res(n, 0);

        int lb = 0, lc = 0;
        for(int i = 0; i < n; i++) {
            res[i] += lc;
            if(boxes[i] == '1') lb++;
            lc += lb;
        }

        int rb = 0, rc = 0;
        for(int i = n-1; i >= 0; i--) {
            res[i] += rc;
            if(boxes[i] == '1') rb++;
            rc += rb;
        }

        return res;
    }
};
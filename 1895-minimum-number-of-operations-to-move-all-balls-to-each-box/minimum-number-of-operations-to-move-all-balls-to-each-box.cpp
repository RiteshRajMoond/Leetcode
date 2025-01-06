class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> res;

        for(int i = 0; i < n; i++) {
            int l = 0;
            for(int j = 0; j < i; j++) {
                if(boxes[j] == '1') l += (i-j);
            }

            int r = 0;
            for(int j = i+1; j < n; j++) {
                if(boxes[j] == '1') l += (j-i);
            }

            res.push_back(l+r);
        }
        return res;
    }
};
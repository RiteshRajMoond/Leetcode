class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        int r = 0, c = m-1;
        while(r < n && c >= 0) {
            int el = matrix[r][c];

            if(el == target) return true;
            else if (el < target) r++;
            else c--;
        }

        return false;
    }
};
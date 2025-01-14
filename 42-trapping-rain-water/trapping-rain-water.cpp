class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int i = 0, j = n-1;
        int l = height[i], r = height[j];
        
        int res = 0;
        while(i < j) {
            if(l >= r) {
                res += (r - height[j]);
                j--;
                r = max(r, height[j]);
            } else {
                res += (l - height[i]);
                i++;
                l = max(l, height[i]);
            }
        }
        return res;
    }
};
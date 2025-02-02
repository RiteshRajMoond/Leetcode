class Solution {
public:
    bool check(vector<int>& arr) {
        int n = arr.size();
        int cnt = 0;
        for (int i = 1; i < n; i++) {
            int last = arr[i - 1], cur = arr[i];
            if (last > cur)
                cnt++;
            if (cnt == 2)
                return false;
        }
        cnt = (arr.back() > arr.front()) ? ++cnt : cnt;
        return cnt < 2;
    }
};
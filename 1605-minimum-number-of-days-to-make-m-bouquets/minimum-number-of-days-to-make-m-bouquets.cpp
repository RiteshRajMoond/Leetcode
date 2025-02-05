class Solution {
    bool if_possible(int day, int m, int k, vector<int>& bloom) {
        int cnt = 0, num = 0;
        for(int i = 0; i < bloom.size(); i++) {
            if(bloom[i] <= day) {
                cnt++;
                if(cnt == k) {
                    num++;
                    cnt = 0;
                }
            } else {
                cnt = 0;
            }
        }
        return num >= m;
    }

public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if((long)m*k > n) return -1;

        int low = 1, high = *max_element(bloomDay.begin(), bloomDay.end());
        int res = high;
        while(low <= high) {
            int mid = low + (high - low)/2;
            if(if_possible(mid, m, k, bloomDay)) {
                res = mid;
                high = mid-1;
            } else low = mid+1;
        }

        return res;
    }
};
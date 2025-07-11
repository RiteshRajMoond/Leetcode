#define ll long long
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        vector<int> cnt(n, 0);
        priority_queue<int, vector<int>, greater<int>> free;
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>> > busy;

        for(int i = 0; i < n; i++) free.push(i);

        for(auto& meet : meetings) {
            ll start = meet[0], end = meet[1];

            while(!busy.empty() && busy.top().first <= start) {
                free.push(busy.top().second);
                busy.pop();
            }

            if(!free.empty()) {
                int room = free.top(); free.pop();
                busy.emplace(end, room);
                cnt[room]++;
            } else {
                auto [av_time, room] = busy.top(); busy.pop();
                busy.emplace(av_time + end - start, room);
                cnt[room]++;
            }
        }
        return max_element(cnt.begin(), cnt.end()) - cnt.begin();
    }
};
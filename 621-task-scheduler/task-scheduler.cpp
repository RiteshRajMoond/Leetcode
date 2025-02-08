class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for (char& c : tasks) {
            freq[c - 'A']++;
        }

        priority_queue<int> pq;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                pq.push(freq[i]);
            }
        }

        queue<pair<int, int>> q; // tasks_left, next_available_time

        int time = 0;
        while (!pq.empty() || !q.empty()) {
            int cur_task = -1;
            if (!pq.empty()) {
                cur_task = pq.top();
                pq.pop();
                cur_task--;
            }
            time++;
            if (cur_task > 0)
                q.push({cur_task, time + n});

            if (!q.empty() && q.front().second == time) {
                pq.push(q.front().first);
                q.pop();
            }
        }
        return time;
    }
};
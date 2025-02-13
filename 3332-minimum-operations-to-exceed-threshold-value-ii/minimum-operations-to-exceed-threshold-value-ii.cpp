#define ll long long

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        for(int & num : nums) pq.push(num);

        int num_ops = 0;
        while(pq.size() >= 2 && pq.top() < k) {
            ll x = pq.top(); pq.pop();
            ll y = pq.top(); pq.pop();

            ll to_be_added = min(x, y)*2 + max(x, y);
            pq.push(to_be_added);
            num_ops++;
            if(pq.top() >= k) break;
        }

        return num_ops;
    }
};
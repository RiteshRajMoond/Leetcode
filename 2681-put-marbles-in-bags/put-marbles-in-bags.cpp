class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        if(k == 1) return 0;
        priority_queue<int> mn;
        priority_queue<int, vector<int>, greater<int>> mx;

        int n = weights.size();

        for(int i = 0; i < n-1; i++) {
            int sum = weights[i]+weights[i+1];

            mx.push(sum);
            mn.push(sum);

            if(mx.size() > k-1) mx.pop();
            if(mn.size() > k-1) mn.pop();
        }

        long long minimum = 0, maximum = 0;
        for(int i = 0; i < k-1; i++) {
            minimum += mn.top();
            maximum += mx.top();

            mn.pop();
            mx.pop();
        }

        return maximum - minimum;
    }
};
class Twitter {
    int timestamp;
    unordered_map<int, set<int>> following; // user_id -> people this user follows following 
    unordered_map<int, vector<pair<int, int>>> tweets; // user_id -> {timestamp, tweet_id}
public:
    Twitter() {
        timestamp = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timestamp++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> feed;
        priority_queue<pair<int, int>> pq; // timestamp, tweetId;

        for(const auto& tweet : tweets[userId]) pq.push(tweet);

        for(const auto& user_id : following[userId]) {
            for(const auto& tweet : tweets[user_id]) {
                pq.push(tweet);
            }
        }

        for(int i = 0; i < 10 && !pq.empty(); i++) {
            feed.push_back(pq.top().second);
            pq.pop();
        }

        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
class Twitter {
    int timestamp;

    // user_id -> list of people following
    unordered_map<int, unordered_set<int> > followers; 

    // user_id -> list of {timestamp, tweet_id}
    unordered_map<int, vector<pair<int, int>> > tweets;
public:
    Twitter() {
        timestamp = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timestamp++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue< pair<int, int> > pq; // {timestamp, tweet_id};

        // user's own tweet push
        for(const auto& tweet : tweets[userId]) {
            pq.push(tweet);
        }

        // push the tweets of the people users follows
        for(const auto& follower_id : followers[userId]) {
            for(const auto& tweet : tweets[follower_id]) {
                pq.push(tweet);
            }
        }

        vector<int> feed;
        for(int i = 0; i < 10 && !pq.empty(); i++) {
            feed.push_back(pq.top().second);
            pq.pop();
        }

        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        followers[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followers[followerId].erase(followeeId);
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
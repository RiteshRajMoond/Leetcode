class Twitter {
    unordered_map< int, unordered_set<int> > followers; // user_id -> set of followers
    unordered_map< int, vector<pair<int, int>> >  tweets; // user_id -> {time_stamp, tweet_id}
    int timestamp;
public:
    Twitter() {
        timestamp = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timestamp++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue< pair<int, int> > pq; // maxHeap -> {timestamp, tweetId}

        // Add users tweets
        for(const auto& tweet : tweets[userId]) {
            pq.push(tweet);
        }

        // Add followee's tweets
        for(int followeeId : followers[userId]) {
            for(const auto& tweet : tweets[followeeId]) {
                pq.push(tweet);
            }
        }

        // get last 10 posts
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
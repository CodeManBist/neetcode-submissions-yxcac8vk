class Twitter {
public:
    Twitter() {
        
    }
    
    int time = 0;
    unordered_map<int, vector<pair<int, int>>> tweets;
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({ time++, tweetId });
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        vector<pair<int, int>> allTweets;

        for(auto tweet: tweets[userId]) {
            allTweets.push_back(tweet);
        }

        for(int followee: following[userId]) {
            for(auto tweet: tweets[followee]) {
                allTweets.push_back(tweet);
            }
        }

        sort(allTweets.begin(), allTweets.end(), greater<pair<int, int>>());

        for(int i = 0; i < 10 && i < allTweets.size(); i++) {
            ans.push_back(allTweets[i].second);
        }

        return ans;
    }

    unordered_map<int, unordered_set<int>> following;
    
    void follow(int followerId, int followeeId) {
        if(followerId == followeeId) return;
        
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};

class Twitter {
public:
    int timeStamp;
    unordered_map<int, vector<pair<int,int>>> tweets;
    unordered_map<int, unordered_set<int>> following;

    Twitter() {
        timeStamp = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timeStamp++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> result;

        priority_queue<vector<int>> pq;

        // user khud ko follow kare (important trick)
        following[userId].insert(userId);

        for(int followee : following[userId]) {
            auto &t = tweets[followee];
            if(!t.empty()) {
                int idx = t.size() - 1;
                pq.push({t[idx].first, t[idx].second, followee, idx});
            }
        }

        while(!pq.empty() && result.size() < 10) {
            auto top = pq.top(); pq.pop();

            int tweetId = top[1];
            int user = top[2];
            int idx = top[3];

            result.push_back(tweetId);

            if(idx > 0) {
                auto &t = tweets[user];
                pq.push({t[idx-1].first, t[idx-1].second, user, idx-1});
            }
        }

        return result;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId != followeeId)
            following[followerId].erase(followeeId);
    }
};

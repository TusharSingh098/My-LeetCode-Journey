class Twitter 
{
private:
    int time;
    unordered_map<int, vector<pair<int, int>>> tweets;
    unordered_map<int, unordered_set<int>> following;

public:
    Twitter() : time(0) {}
    
    void postTweet(int userId, int tweetId) 
    {
        tweets[userId].push_back({time++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) 
    {
        priority_queue<pair<int, pair<int, int>>> pq;

        if (tweets.count(userId) && !tweets[userId].empty())
        {
            int idx = tweets[userId].size() - 1;
            pq.push({tweets[userId][idx].first, {idx, userId}});
        }

        for (int followeeId : following[userId])
        {
            if (tweets.count(followeeId) && !tweets[followeeId].empty())
            {
                int idx = static_cast<int>(tweets[followeeId].size()) - 1;
                pq.push({tweets[followeeId][idx].first, {idx, followeeId}});
            }
        }

        vector<int> ans;
        while (!pq.empty() && ans.size() < 10)
        {
            auto top{pq.top()};
            pq.pop();

            int currTime{top.first};
            int idx{top.second.first};
            int uId{top.second.second};

            ans.push_back(tweets[uId][idx].second);

            if (idx > 0) pq.push({tweets[uId][idx - 1].first, {idx - 1, uId}});
        }

        return ans;
    }
    
    void follow(int followerId, int followeeId) 
    {
        if (followerId != followeeId) following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) 
    {
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
struct TweetNode 
{
    int timestamp;
    int tweetIdx;
    int userId;

    bool operator<(const TweetNode& other) const 
    {
        return timestamp < other.timestamp;
    }
};

class Twitter {
private:
    int time;
    unordered_map<int, vector<pair<int, int>>> tweets;
    unordered_map<int, unordered_set<int>> following;

public:
    Twitter() : time(0) {}
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<TweetNode> pq;

        if (tweets.count(userId) && !tweets[userId].empty()) 
        {
            int idx = static_cast<int>(tweets[userId].size()) - 1;
            pq.push({tweets[userId][idx].first, idx, userId});
        }

        if (following.count(userId)) 
        {
            for (int followeeId : following[userId]) 
            {
                if (tweets.count(followeeId) && !tweets[followeeId].empty()) 
                {
                    int idx = static_cast<int>(tweets[followeeId].size()) - 1;
                    pq.push({tweets[followeeId][idx].first, idx, followeeId});
                }
            }
        }

        vector<int> ans;
        while (!pq.empty() && ans.size() < 10) 
        {
            TweetNode top = pq.top();
            pq.pop();

            ans.push_back(tweets[top.userId][top.tweetIdx].second);

            if (top.tweetIdx > 0) 
            {
                int nextIdx = top.tweetIdx - 1;
                pq.push({tweets[top.userId][nextIdx].first, nextIdx, top.userId});
            }
        }

        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) 
        {
            following[followerId].insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        if (following.count(followerId)) 
        {
            following[followerId].erase(followeeId);
        }
    }
};

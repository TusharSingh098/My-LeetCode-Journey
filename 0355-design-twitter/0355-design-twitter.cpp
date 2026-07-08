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
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        for (auto& tweet: tweets[userId])
        {
            pq.push(tweet);
            if (pq.size() > 10) pq.pop();
        }

        for (int follower: following[userId])
        {
            for (auto& tweet: tweets[follower])
            {
                pq.push(tweet);
                if (pq.size() > 10) pq.pop();
            }
        }

        vector<int> ans;
        while (!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }
    
    void follow(int followerId, int followeeId) 
    {
        following[followerId].insert(followeeId);
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
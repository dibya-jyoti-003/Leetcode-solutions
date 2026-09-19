class Twitter {
public:
    unordered_map<int,vector<pair<int,int>>> post;
    unordered_map<int , set<int>> following;
    int time;

    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        post[userId].push_back({time++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>> pq;
        for (auto i: following[userId]){
            for (auto p : post[i]){
                pq.push(p);
            }
        }
        vector<int> ans ; 
        for (auto p : post[userId])pq.push(p);
        int cnt= 0;
        while (cnt++<10 and !pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans ;
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
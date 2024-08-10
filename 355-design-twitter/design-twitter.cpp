//Time: O(n) & Space: O(n)
class Twitter {
private:
    vector<pair<int,int>> posts; // pairs: [user, tweet]
    unordered_map<int,unordered_set<int>> followMap; // hash map: {user -> people they follow}

public:
    Twitter() {}
    
    void postTweet(int userId, int tweetId) {
        posts.push_back({userId, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        int c=10;
        for(int i=posts.size()-1;i>=0;i--){
          if(!c) break;
          int followingId = posts[i].first;
          int tweetId = posts[i].second;
          unordered_set<int> followers = followMap[userId];
          if(followers.find(followingId) != followers.end() || followingId == userId){
              ans.push_back(tweetId);
              c--;
          }
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followMap[followerId].erase(followeeId);
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
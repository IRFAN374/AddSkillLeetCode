    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        
        if(f.find(followerId) == f.end()){
            set<int>s;
            s.insert(followeeId);
            f[followerId] = s;
        }
        else{
            f[followerId].insert(followeeId);
        }
        
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        
        f[followerId].erase(followeeId);
        
        if(f[followerId].size() == 0)
            f.erase(followerId);
        
    }
};

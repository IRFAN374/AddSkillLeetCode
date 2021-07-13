class Solution {
public:
    
    class sortBySec{
        
        public:
           int operator() (const pair<int,int> &a,const pair<int,int>&b){
               return a.second < b.second;
           }
    };
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,sortBySec>pq;
        
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        
        for(auto it=mp.begin();it!=mp.end();it++){
            pq.push(make_pair(it->first,it->second));
        }
        vector<int> res;
        for(int i=0;i<k;i++){
            pair<int,int> val = pq.top();
            res.push_back(val.first);
            pq.pop();
        }
        // while(!pq.empty()){
        //     pair<int,int> val = pq.top();
        //     cout<<val.first<<" "<<val.second<<endl;
        //     pq.pop();
        // }
        return res;
    }
};

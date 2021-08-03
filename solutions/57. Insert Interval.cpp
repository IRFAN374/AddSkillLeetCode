class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        vector<vector<int>> ans;
        
        // first push all element which last value are less than newInterval first element
        
        int i =0, len = intervals.size() ;
        while(i<len && intervals[i][1] < newInterval[0]){
            ans.push_back(intervals[i]);
            i++;
        }
        // second  push all element which are going to be merge with newInterval
        
        while(i<len && intervals[i][0]<= newInterval[1]){
            
            newInterval[0] = min(newInterval[0],intervals[i][0]);
            newInterval[1] = max(newInterval[1],intervals[i][1]);
            i++;
            
        }
        ans.push_back(newInterval);
        
        // push are element which first value gretaer than newInterval last element
        while(i<len){
            ans.push_back(intervals[i++]);
        }
        
        return ans;
    }
};

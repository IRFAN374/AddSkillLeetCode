class Solution {
public:
    static bool comp(vector<int>&a,vector<int>&b){
        return a[0] < b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int len = intervals.size();
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end(),comp);
        for(int i=0;i<len;i++){
            vector<int> temp = intervals[i];
            int j = i+1;
            while(j<len && temp[1]>= intervals[j][0] ){
                temp[0]=temp[0];
                temp[1]=max(temp[1],intervals[j][1]);
                j++;
            }
            i=j-1;
            ans.push_back(temp);
        }
        return ans;
    }
};

class Solution {
public:
    vector<vector<int>> dp;
    int strangePrinter(string s) {
        dp.resize(102,vector<int>(102,0));
        int len = s.length()-1;
        return helper(s,0,len);
    }
    int helper ( string str, int start, int end){
        if(start > end ) return 0;
        
        if(dp[start][end] > 0) return dp[start][end];
        
        int ans = INT_MAX;
        ans = min(ans, 1+helper(str,start+1,end));
        
        
        for(int x= start+1; x<=end;x++){
            if(str[start]==str[x]){
                ans = min (ans, helper(str, start+1,x-1)+ helper(str,x,end));
            }
        }
        dp[start][end]= ans;
        return ans;
    }
};

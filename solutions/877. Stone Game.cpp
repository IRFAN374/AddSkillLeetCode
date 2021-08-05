class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int len = piles.size();
        pair<int,int> dp[len][len];
        
        for(int i=0;i<len;i++){
            dp[i][i].first = piles[i];
            dp[i][i].second = 0;
        }
        for(int turn = 1;turn<len;turn++){
            for(int i=0;i<len-turn;i++){
                
                int j = i + turn;
                int pickLeft = piles[i] + dp[i+1][j].second;
                int pickRight = piles[j] + dp[i][j-1].second;
                dp[i][j].first = max(pickLeft,pickRight);
                if(dp[i][j].first == pickLeft){
                    dp[i][j].second = dp[i+1][j].first;
                }else{
                    dp[i][j].second = dp[i][j-1].first;
                }  
            }
        }
        return dp[0][len-1].first > dp[0][len-1].second;
    }
};

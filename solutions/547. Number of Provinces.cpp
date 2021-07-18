class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int ro = isConnected.size();
        int col = ro;
        int count = 0;
        vector<bool>visit(col,false);
        for(int u = 0; u<ro;u++){
            if(visit[u] == false){
                DFS(isConnected,visit,u,col);
                count++;
            }
        }
        
        return count;
    }
    void DFS(vector<vector<int>>&isConnected,vector<bool>&visit,int src,int col){
        
        visit[src] = true;
        for(int i = 0 ;i<col;i++){
            if(visit[i]==false && isConnected[src][i]==1){
                DFS(isConnected, visit, i,col);
            }
        }
    }
};

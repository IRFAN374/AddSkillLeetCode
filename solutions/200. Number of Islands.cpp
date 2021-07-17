public:
    int numIslands(vector<vector<char>>& grid) {
        int ro = grid.size();
        int col = grid[0].size();
        vector<vector<bool>>visit(ro, vector<bool>(col,false));
        int count = 0;
        for(int i=0; i<ro; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j]=='1' && visit[i][j]==false){
                    //visit[i][j]=true;
                    DFS(grid,visit,ro,col,i,j);
                    count++;
                }
                // cout<<"visit array is:"<<count<<endl;
                // for(int k=0;k<visit.size();k++){
                //     for(int l=0;l<visit[k].size();l++){
                //         cout<<visit[k][l]<<" ";
                //     }
                //     cout<<endl;
                // }
            }
        }
        return count;
    }
    
    
    bool isValid(int ro,int col,int start_ro,int start_col){
        if(start_ro <ro && start_col <col && start_ro>=0 && start_col>=0){
            return true;
        }else {
            return false;
        }
    }
    
    
    void DFS(vector<vector<char>>&grid, vector<vector<bool>>&visit, int ro,int col, int start_ro,int start_col){
        // if( isValid(ro,col,start_ro,start_col)==false) return;
        
        visit[start_ro][start_col] = true;
        
        // cout<<start_ro<<" "<<start_col<<endl;
        if(isValid(ro,col,start_ro+1,start_col) && grid[start_ro+1][start_col]=='1' && visit[start_ro+1][start_col]==false) DFS(grid,visit,ro,col,start_ro+1,start_col);
       
        if(isValid(ro,col,start_ro-1,start_col) && grid[start_ro-1][start_col]=='1' && visit[start_ro-1][start_col]==false)  DFS(grid,visit,ro,col,start_ro-1,start_col);
        
        if(isValid(ro,col,start_ro,start_col+1) && grid[start_ro][start_col+1]=='1' && visit[start_ro][start_col+1]==false)  DFS(grid,visit,ro,col,start_ro,start_col+1);
        
        if(isValid(ro,col,start_ro,start_col-1) && grid[start_ro][start_col-1]=='1' && visit[start_ro][start_col-1]==false)  DFS(grid,visit,ro,col,start_ro,start_col-1);
        return;
    }
};

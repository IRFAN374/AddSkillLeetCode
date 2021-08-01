class Solution {
public:
    unordered_map<int, int> mp; //mjhe iss m id store krni h aur uss k corresponding area
    //dfs helper function to find out ki kaunse 1s aas paas h aur island bna rhe h
    int assignIdAndReturnArea(vector<vector<int>>& grid, int i, int j, int id){
       
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] != 1) 
            return 0;
         grid[i][j] = id;
        return 1 + assignIdAndReturnArea(grid, i + 1, j, id) + assignIdAndReturnArea(grid, i - 1, j, id) + assignIdAndReturnArea(grid, i, j + 1, id) + assignIdAndReturnArea(grid, i, j - 1, id);
    }
    int largestIsland(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int gridId = 2; //starting grid id from 2 q ki 0 and 1 already occupied h
        int max_area = 0;
        mp.insert({0,0}); //jb bhi koi 0 encounter ho toh uska area 0 hi rkhna h
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if (grid[i][j] == 1){
                    int size = assignIdAndReturnArea(grid, i, j, gridId);
                    // cout<<gridId<<"  "<<size<<endl;
                    max_area = max(max_area,size);
                    mp.insert({gridId, size});
                    gridId++; 
                }
            }
        }
        // cout<<"Grid is: "<<endl;
        // for(int i=0;i<r;i++){
        //     for(int j=0;j<c;j++){
        //         cout<<grid[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<"map is: "<<endl;
        // for(auto it=mp.begin();it!=mp.end();it++){
        //     cout<<it->first<<" "<<it->second<<endl; 

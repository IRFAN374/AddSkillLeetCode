class Solution {
public:
    int numTilePossibilities(string tiles) {
        sort(tiles.begin(),tiles.end());
        int result = -1;
        helper(tiles, result, 0);
        return result;
    }
    void helper(string tiles,int &result, int index){
        result++;
        for(int i=index;i<tiles.size();i++){
            if(i!=index && tiles[i]==tiles[index]) continue;
            swap(tiles[i],tiles[index]);
            helper(tiles,result, index+1);
        }
        return ;
    }
};

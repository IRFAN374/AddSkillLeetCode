class Solution {
public:
    // class compByFirst{
    //     public:
    //      int operator()(const pair<int,int>&a,const pair<int,int>&b){
    //          return a.first > b.first;
    //      }
    // };
    struct Point{
        int val;
        int row_val;
        int col_val;
    };
    class compByVal{
        public:
        int operator()(const Point &p1,const Point &p2){
            return p1.val > p2.val;
        }
    };
    
    int kthSmallest(vector<vector<int>>& matrix, int k) {
      //priority_queue<pair<int,int> vector<pair<int,int>>, compByFirst)pq;
      priority_queue<Point,vector<Point>,compByVal>pq;
        int row = matrix.size();
      int col = matrix[0].size();
        Point p,temp;
      for(int i=0;i<row;i++){
          p.val = matrix[i][0];
          p.row_val = i;
          p.col_val = 0;
          pq.push(p);
      }
        k--;
      while(!pq.empty() && k>0){
          temp = pq.top();pq.pop();
          k--;
          if(temp.row_val<row && temp.col_val<col-1){
              ++temp.col_val;
              p.val = matrix[temp.row_val][temp.col_val];
              p.row_val = temp.row_val;
              p.col_val = temp.col_val;
              pq.push(p);
          }
          
      }
        return pq.top().val;
        
    }
};

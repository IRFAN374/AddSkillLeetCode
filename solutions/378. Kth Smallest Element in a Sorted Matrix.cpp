// using binary search
class Solution {
public:
    
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int row = matrix.size();
        int col = matrix[0].size();
        int low = matrix[0][0],high= matrix[row-1][col-1];
        
        while(low<high){
            int mid = low + (high-low)/2;
            if(matrixSearchCount(matrix,k,col,mid)){
                high = mid ;
            }else{
                low = mid + 1;
            }
        }
        return low;
    }
    
    bool matrixSearchCount(vector<vector<int>>&matrix,int k,int n,int mid){
        int row =0,col=n-1;
        int count =0;
        while(row<n && col>=0){
            int val = matrix[row][col];
            if(val>mid){
                col--;
            }else{
                count = count + col + 1;
                row++;
            }
        }
        return count>=k;
    }
    
};

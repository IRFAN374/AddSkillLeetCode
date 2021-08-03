class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> ans;
        int first, second,start=0,j;
        for(int i=0;i< firstList.size();i++){
           // cout<<"Start is: "<<start<<endl;
            for( j=start;j<secondList.size();j++){
                if(firstList[i][1]>=secondList[j][0]){
                    first = max(firstList[i][0],secondList[j][0]);
                    second = min(firstList[i][1],secondList[j][1]);
                    if(second>=first){
                        ans.push_back({first,second});
                        start=j;
                    }
                }else{
                    break;
                }
            }
            
        }
        return ans;
    }
};

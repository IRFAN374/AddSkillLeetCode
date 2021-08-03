class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int first = 0, second =0, start, end;
        int totalTime =0;
        
        for(int i=0;i<timeSeries.size();i++){
            start= timeSeries[i];
            end = start + duration;
            if( second >= start){
                // merge them
                first = min(start,first);
                second = max(end, second);
            }else{
                totalTime += second - first;
                first = start;
                second = end;
            }
        }
        
        totalTime += second - first;
        return totalTime;
    }
};

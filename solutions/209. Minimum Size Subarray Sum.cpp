class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int len = INT_MAX;
        int left=0, right= 0,cs =0;
        while(right < nums.size()){
            
            while((cs < target) && (right<nums.size()) ){
                cs += nums[right];
                right++;
            }
           // cout<<"CurrS-Sum: right  "<<cs<<endl;
            while((cs >= target) && (left < right)){
                len = min( len, right-left);
                cs -= nums[left];
                left++;
            }
           // cout<<"CurrS-Sum: left  "<<cs<<endl;
            if(cs == target){
                len = min( len, right-left);
               // cout<<"len is:"<<len<<endl;
            }
        }
        
        return len==INT_MAX ? 0 : len;
    }
};

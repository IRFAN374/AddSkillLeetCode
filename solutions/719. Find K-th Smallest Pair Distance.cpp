class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
     
        sort(nums.begin(),nums.end());
        
        vector<int>freq(nums.size(),0);
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]){
              freq[i] = 1 + freq[i-1];  
            }
        }
        
        int width = 2 * nums[nums.size()-1];
        vector<int> prefix(width,0);
        int left =0;
        for(int i=0;i<width;i++){
            while(left<nums.size() && nums[left]==i) left++;
            prefix[i]=left;
        }
        
        int low =0, high = nums[nums.size()-1] - nums[0];
        while(low < high){
            int mid = low + (high - low)/2;
            int count=0;
            for(int i=0;i<nums.size();i++){
                count += prefix[nums[i]+mid] - prefix[nums[i]] + freq[i]; 
            }
            if(count>=k) high = mid;
            else low = mid + 1;
        }
        return low;
    }
};

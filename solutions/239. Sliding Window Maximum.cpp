class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        for(int i=0;i<k;i++){
            while(!dq.empty() && nums[i]>=nums[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        
        vector<int> ans;
        for(int i=k;i<nums.size();i++){
            ans.push_back(nums[dq.front()]);
            while(!dq.empty() && nums[i]>=nums[dq.back()]){
                dq.pop_back();
            }
            
            while(!dq.empty() && dq.front()<= i-k){
                dq.pop_front();
            }
            dq.push_back(i);
        }
        ans.push_back(nums[dq.front()]);
        return ans;
    }
};

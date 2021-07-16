class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int>numsArray(nums);
        numsArray.insert(numsArray.end(),nums.begin(),nums.end());
        
        stack<int>st;
        vector<int>result(numsArray.size());
        for(int i=numsArray.size()-1;i>=0;i--){
            if(st.empty()){
                result[i] = -1;
            }else{
                if(st.top()>numsArray[i]){
                    result[i] = st.top();
                }else{
                    while(!st.empty() && st.top()<=numsArray[i]){
                        st.pop();
                    }
                    if(st.empty()) result[i]=-1;
                    else result[i] = st.top();
                }
            }
            st.push(numsArray[i]);
        }
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            ans.push_back(result[i]);
        }
        return ans;
    }
};

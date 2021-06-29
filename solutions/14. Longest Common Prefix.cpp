class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        int sm_len=INT_MAX;
        string sh_str="";
        for(int i=0;i<strs.size();i++){
            if(sm_len>strs[i].length()){
               sm_len= strs[i].length();
               sh_str=strs[i];
            }
            
        }
        if(sm_len==INT_MAX){
            return "";
        }
        int i;
        string ans="";
        for( i=0;i<sm_len;i++){
            int j;
            for( j=0;j<strs.size();j++){
                if(sh_str[i]!=strs[j][i]){
                    break;
                }
            }
            if(j!=strs.size()){
                break;
            }else{
                ans+=sh_str[i];
            }
        }
        
        return ans;
        
    }
};

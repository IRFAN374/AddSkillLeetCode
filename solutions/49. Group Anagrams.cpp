class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mapp;
        for(int i=0;i<strs.size();i++)
        {
            string s1=strs[i];
            string s2=strs[i];
            sort(s1.begin(),s1.end());
            mapp[s1].push_back(s2);
        }
        vector<vector<string>>ans;
        for(auto x:mapp)
        {
            ans.push_back(x.second);
        }
        return ans;
    }
};

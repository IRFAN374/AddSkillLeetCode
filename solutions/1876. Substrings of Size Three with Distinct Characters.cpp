class Solution {
public:
    int countGoodSubstrings(string s) {
        if(s.length()<3) return 0;
        char first,second,third;
        int ans = 0;
        first = s[0];
        second = s[1];
        third = s[2];
        for(int i=3;i<s.length();i++){
           
            if(first!=second && second!=third && first!=third){
                ans++;
            }
            first=second;
            second = third;
            third = s[i];
        }
         if(first!=second && second!=third && first!=third){
                ans++;
            }
        return ans;
    }
};

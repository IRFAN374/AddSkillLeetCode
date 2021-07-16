class Solution {
public:
    char findTheDifference(string s, string t) {
        int sumS =0,sumT =0;
      for(char ch: s){
        sumS = sumS + ch;
      }
      for(char ch: t){
        sumT = sumT + ch;
      }
      return sumT-sumS;
    }
};

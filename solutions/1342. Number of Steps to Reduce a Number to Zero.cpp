class Solution {
public:
    int numberOfSteps(int num) {
      int count =0 ;
      while(num!=0){
        if((num & 0x1)==0){
          num=num>>1;
        }else{
          num--;
        }
        count++;
      }
      return count;
    }
};

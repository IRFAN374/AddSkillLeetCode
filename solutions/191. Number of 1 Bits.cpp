class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count=0;
        for(int pos=0;pos<32;pos++){
            if(n & (1<<pos)){
                count++;
            }
        }
        return count;
    }
};

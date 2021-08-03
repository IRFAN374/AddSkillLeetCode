class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0 || prices.size()==1) return 0;
        int profit=0;
        int minPrice=INT_MAX;
        for(int i=0;i<prices.size();i++){
            if(prices[i]<minPrice){
                minPrice=prices[i];
            }else if(profit < (prices[i]-minPrice)) {
                profit=prices[i]-minPrice;
            }
        }
        return profit;
    }
};

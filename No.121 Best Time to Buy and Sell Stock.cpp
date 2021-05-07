class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxP=0,res=0;
        for(int i=prices.size()-1;i>=0;i--){
            maxP=max(maxP,prices[i]);
            res=max(res,maxP-prices[i]);
        }
        return res;
    }
};
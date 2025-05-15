class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int pri=prices[0];
        int profit=0;
        for(int i=0;i<prices.size();i++){
            int c=prices[i]-pri;
            profit=max(profit,c);
            pri=min(pri,prices[i]);
        }
        return profit;
    }
};
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l=0;
        int r=1;
        int maxi=0;

        while(r<prices.size()){
            if(prices[l]>prices[r]){
                l = r;
                r++;
                continue;
            }
            int profit = prices[r]-prices[l];
            maxi=max(maxi,profit);
            r++;
        }

        return maxi;
    }
};

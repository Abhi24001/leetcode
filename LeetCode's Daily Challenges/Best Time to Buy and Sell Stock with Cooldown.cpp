class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 0) return 0;
        vector<int> stock(n + 1);
        vector<int> money(n + 1);
        stock[1] = -prices[0];
        money[1] = 0;
        for(int i = 1; i < n; ++i){
            stock[i + 1] = max(stock[i], money[i - 1] - prices[i]);
            money[i + 1] = max(stock[i] + prices[i], money[i]);
        }
        return money[n];
    }
};

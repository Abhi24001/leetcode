class Solution {
public:
    int numSquares(int n) {
        vector<int> perfectSquares;
        for(int i=1;i*i<=n;i++){
            perfectSquares.push_back(i*i);
        }
        vector<int> dp(n+1,INT_MAX);
        dp[0] = 0;
        for(int i=1;i<=n;i++){
            for(auto& j:perfectSquares){
                if(j<=i && dp[i-j]!=INT_MAX){
                    dp[i] = min(dp[i],1+dp[i-j]);
                }
            }
        }
        return dp[n];
    }
};

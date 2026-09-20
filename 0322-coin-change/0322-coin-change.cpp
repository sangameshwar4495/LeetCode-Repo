class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int inf = 1e9;
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1, 0));
        for(int j=1; j<amount+1; j++){
            dp[0][j] = inf; // no comb possible
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=amount; j++){
                if(coins[i-1]<=j){
                    dp[i][j] = min(dp[i-1][j], dp[i][j-coins[i-1]]+1);
                }else dp[i][j] = dp[i-1][j];
            }
        }

        return dp[n][amount]==inf? -1: dp[n][amount];
    }
};
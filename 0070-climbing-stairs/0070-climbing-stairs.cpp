class Solution {
public:
    int climbStairs(int n) {
        if(n==1||n==2) return n;
        // vector<int> dp(n+1, 0);
        // dp[1] = 1;
        // dp[2] = 2;
        // for(int i=3; i<=n; i++){
        //     // ways[n] = ways[n-1]+ways[n-2]
        //     dp[i] = dp[i-1]+dp[i-2];
        // }
        // return dp[n];

        int dpi_1 = 1; //dp[i-1]
        int dpi_2 = 1;
        int ans = 2;
        for(int i=2; i<=n; i++){
            ans = dpi_1+dpi_2;
            dpi_2 = dpi_1;
            dpi_1 = ans;
        }
        return ans;
    }
};
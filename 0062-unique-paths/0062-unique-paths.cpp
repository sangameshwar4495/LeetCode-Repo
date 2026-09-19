class Solution {
public:
    int dpsol(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1));

        for (int i = m - 2; i >= 0; i--) {
            for (int j = n - 2; j >= 0; j--) {
                dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
            }
        }
        return dp[0][0];
    }

    int ncrsol(int m, int n){
        // this is a discrete math counting problem
        // to reach last cell, you need to go 
        // m-1 steps down and n-1 steps right
        // at each step we get to choose right or down
        // we get to choose only m-1 or n-1 steps
        int s = min(m,n);
        return ncr(m-1+n-1, s-1);
    }
    int ncr(int n, int r){
        long long ans = 1;
        int mul = n;
        for(int i=1; i<=r; i++){
            ans = ans*(n-i+1)/i;
        }
        return ans;
    }
    int uniquePaths(int m, int n) {
        return ncrsol(m,n);
        // return dpsol(m,n);
    }
};
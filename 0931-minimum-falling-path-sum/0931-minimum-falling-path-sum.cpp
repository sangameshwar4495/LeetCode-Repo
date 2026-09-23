class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        // key idea striked
        // for every element the cost to reach there is min
        // when it travels from a min cell above
        // so curr = min(j-1, j, j+1) of previous row
        int n= matrix.size();
        vector<vector<int>> dp(n, vector<int>(n+2, INT_MAX));
        // filling first row
        for(int j=1; j<=n; j++){
            dp[0][j] = matrix[0][j-1];
        }
        // i is same, j is +2(front&back) while indicing take -1
        for(int i=1; i<n; i++){
            for(int j=1; j<=n; j++){
                dp[i][j] = matrix[i][j-1]+min(min(dp[i-1][j-1], dp[i-1][j+1]), dp[i-1][j]);
            }
        }
        int ans = INT_MAX;
        for(int j=1; j<=n; j++){
            ans = min(dp[n-1][j], ans);
        }
        return ans;
    }
};
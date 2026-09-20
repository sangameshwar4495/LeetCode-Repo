class Solution {
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(target+1, 0));
        int inf = INT_MIN;
        int inf_check = inf+1000;
        for(int j=1; j<=target; j++){
            dp[0][j] = inf;
        }
        // state -> max length using i ele to get sum j
        for(int i=1; i<=n; i++){
            for(int j=1; j<=target; j++){
                if(nums[i-1]<=j) dp[i][j] = max(dp[i-1][j], dp[i-1][j-nums[i-1]]+1);
                else dp[i][j] = dp[i-1][j];
            }
        }
        if(dp[n][target]<=inf_check) return -1;
        return dp[n][target];
    }
};
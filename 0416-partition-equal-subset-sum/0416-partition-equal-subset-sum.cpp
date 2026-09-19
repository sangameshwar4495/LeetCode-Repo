class Solution {
public:
    bool findTargetSubset(vector<int>& nums, int target){
        int n = nums.size();
        vector<vector<bool>> dp(n+1, vector<bool>(target+1, false));
        for(int i=0; i<=n; i++) dp[i][0] = true;

        for(int i=1; i<=n; i++){
            for(int j=1; j<=target; j++){
                if(nums[i-1]>j) dp[i][j] = dp[i-1][j];
                else{
                    dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i-1][j];
                }
            }
        }
        return dp[n][target];
    }
    bool canPartition(vector<int>& nums) {
        // find total sum
        int n = nums.size();
        int sum= 0;
        for(int i=0; i<n; i++){
            sum+=nums[i];
        }

        // if sum is odd then it cant be divided into two eq parts
        if(sum%2==1) return false;
        // the sum of subset is half the total sum
        int target = sum/2;
        return findTargetSubset(nums, target);
    }
};
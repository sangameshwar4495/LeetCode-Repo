class Solution {
public:
    int ans = 0;
    void helper(vector<int>& nums, int i, int sum, int target){
        if(nums.size()==i){
            if(sum==target) ans++;
            return;
        }
        helper(nums, i+1, sum+nums[i], target);
        helper(nums, i+1, sum-nums[i], target);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        helper(nums, 0, 0, target);
        return ans;
    }
};
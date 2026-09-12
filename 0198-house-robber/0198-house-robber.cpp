class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];

        int dpn_2 = nums[0];
        int dpn_1 = max(nums[1], dpn_2);
        int curr = max(dpn_1, dpn_2);
        for(int i=2; i<n; i++){
            curr = max(dpn_1, dpn_2+nums[i]);
            dpn_2 = dpn_1;
            dpn_1 = curr;
        }
        return curr;
    }
};
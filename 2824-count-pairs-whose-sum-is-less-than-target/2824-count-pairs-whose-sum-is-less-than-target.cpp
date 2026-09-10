class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        int ans = 0;
        int i=0;
        int j=nums.size()-1;
        sort(nums.begin(), nums.end());
        while(i<j){
            if(nums[i]+nums[j]<target){
                ans+=(j-i);
                // cout<<i<<" "<<j<<endl;
                i++;
            }else{
                j--;
            }
        }
        return ans;
    }
};
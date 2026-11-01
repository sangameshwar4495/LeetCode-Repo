class Solution {
public:
    int merge(int a, int b){
        int temp = b;
        int mul = 1;
        while(temp>0){
            temp/=10;
            mul*=10;
        }
        int ans = b;
        while(a>0){
            ans = mul*(a%10)+ans;
            a/=10;
            mul*=10;
        }
        return ans;
    }
    int minMergedInteger(vector<int>& nums) {
        int ans = INT_MAX;
        for(int i=0; i<nums.size(); i+=2){
            ans = min(ans, merge(nums[i], nums[i+1]));
        }
        return ans;
    }
};
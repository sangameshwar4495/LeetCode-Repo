class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int minIdx = 0;
        int maxIdx = 0;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(nums[minIdx]>nums[i]) minIdx = i;
            if(nums[maxIdx]<nums[i]) maxIdx = i;
        }
        int ans = INT_MAX;
        ans = max(minIdx+1, maxIdx+1); //if((minIdx+1<=n-minIdx) && (maxIdx+1<=n-maxIdx)) 
        ans = min(ans,max(n-minIdx, n-maxIdx)); //else if((minIdx+1>=n-minIdx) && (maxIdx+1>=n-maxIdx)) 
        
        ans = min(ans, min(minIdx+1,n-minIdx)+min(maxIdx+1,n-maxIdx));
        
        return ans; 
    }
};
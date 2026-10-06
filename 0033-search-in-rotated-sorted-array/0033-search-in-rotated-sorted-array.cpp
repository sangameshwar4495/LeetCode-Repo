class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo=0;
        int hi=nums.size()-1;

        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]<nums[hi]){//right sorted
                if(nums[mid]<target && nums[hi]>=target){
                    // the ele is in between the sorted subarray
                    lo = mid+1;
                }else{
                    // if the ele is not in btw the sorted part then obv it is in other half
                    hi=mid-1;
                }
            }else{
                if(nums[mid]>target && nums[lo]<=target) hi=mid-1;
                else lo=mid+1;
            }
        }
        return -1;
    }
};
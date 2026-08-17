class Solution {
public:
    void heapify(vector<int> &nums, int i, int n){
        int maxIdx = i;
        int leftidx = 2*i+1;
        int rightidx = 2*i+2;
        if(leftidx<n && nums[leftidx]>nums[maxIdx]) maxIdx = leftidx;
        if(rightidx<n && nums[rightidx]>nums[maxIdx]) maxIdx = rightidx;

        if(maxIdx!=i){
            swap(nums[maxIdx], nums[i]);
            heapify(nums, maxIdx, n);
        }
    } 
    vector<int> sortArray(vector<int>& nums) {
        // heap sort 
        // cbt is given -> you just need to make it a min heap
        int n = nums.size();
        for(int i=n/2-1; i>=0; i--){
            heapify(nums, i, n);
        }
        for(int i=n-1; i>=0; i--){
            swap(nums[0], nums[i]);
            heapify(nums, 0, i);
        }
        return nums;
    }
};
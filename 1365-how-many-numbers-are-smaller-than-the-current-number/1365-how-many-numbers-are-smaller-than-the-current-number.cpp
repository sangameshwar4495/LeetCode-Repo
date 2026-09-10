class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<pair<int, int>> arr;
        int n = nums.size();
        for(int i=0; i<n; i++){
            arr.emplace_back(nums[i], i);
        }
        sort(arr.begin(), arr.end());
        vector<int> ans(n);
        for(int i=0; i<n; i++){
            if(i>=1 && arr[i].first==arr[i-1].first) ans[arr[i].second] = ans[arr[i-1].second];
            else ans[arr[i].second] = i;
             
        }
        return ans;
    }
};
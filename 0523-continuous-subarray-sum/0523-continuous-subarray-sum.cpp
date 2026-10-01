class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_set<int> s;
        s.insert(0);
        int currsum = nums[0];
        int prevsum = currsum;
        for(int i=1; i<n; i++){
            currsum+=nums[i];
            if(s.count(currsum%k)) return true;
            s.insert(prevsum%k);
            prevsum = currsum; // just to maintain seize 2
        }
        return false;
    }
};
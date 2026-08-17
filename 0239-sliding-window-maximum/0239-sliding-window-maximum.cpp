class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        // pq
        priority_queue<pair<int, int>> pq;
        for(int i=0; i<k-1; i++){
            pq.push(make_pair(nums[i],i));
        }
        int i=k-1;
        while(i<n){
            pq.push(make_pair(nums[i],i));
            while(pq.top().second <= (i-k)) pq.pop();
            ans.push_back(pq.top().first);
            i++;
        
        }
        return ans;
    }
};
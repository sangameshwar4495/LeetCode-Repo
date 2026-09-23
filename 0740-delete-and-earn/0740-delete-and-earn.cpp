class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        // unofortunately,
        // i saw an hint in the discussion
        // please dont see anything and try to solve
        // additional lines just to make code out of scope
        // 

        //
        map<int,int> m;
        for(int ele : nums) m[ele]++;
        int n = m.size();
        vector<int> dp(n);
        vector<pair<int, int>> arr(n);
        int i=0;
        for(auto p: m){
            arr[i] = make_pair(p.first, p.first*p.second);
            i++;
        }
        dp[0] = arr[0].second;
        if(n==1) return dp[0];
        
        if(arr[1].first-1!=arr[0].first) dp[1] = arr[1].second+dp[0];
        else dp[1] = max(arr[1].second, dp[0]);

        for(i=2; i<n; i++){
            if(arr[i].first-1==arr[i-1].first) 
            dp[i] = max(dp[i-1], dp[i-2]+arr[i].second);
            
            else dp[i] = max(dp[i-2],dp[i-1])+arr[i].second;
        }
        return dp[n-1];
    }
};
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(); 
        vector<bool> vis(n,0);
        vis[0]=1;
        for(int i=0; i<n-1; i++){
            int jumps = nums[i];
            if(vis[i]){
                while(jumps>0){
                    if(i+jumps<n) vis[i+jumps] = 1;
                    jumps--;
                }
            }
        }
        return vis[n-1];
    }
};
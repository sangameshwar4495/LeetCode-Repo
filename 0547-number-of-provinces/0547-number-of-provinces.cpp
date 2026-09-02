class Solution {
public:
    void dfs(int i, vector<vector<int>>& isConnected, vector<bool> &vis){
        vis[i] = 1;
        for(int j=0; j<vis.size(); j++){
            if(isConnected[i][j]==1){
                if(!vis[j]) dfs(j, isConnected, vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> vis(n, false);
        int ans = 0;
        for(int i=0; i<n; i++){
            if(!vis[i]){
                ans++;
                dfs(i, isConnected, vis);
            }
        }
        return ans;
    }
};
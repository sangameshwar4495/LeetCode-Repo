class Solution {
public:
    void dfs(int src, vector<vector<int>>& rooms, vector<bool>& vis){
        vis[src] = true;
        for(int v: rooms[src]){
            if(!vis[v]) dfs(v, rooms, vis);
        }
    } 
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        if(n==0) return true;
        vector<bool> vis(n,false);
        dfs(0,rooms, vis);
        for(bool f: vis) if(!f) return false;
        return true;
    }
};
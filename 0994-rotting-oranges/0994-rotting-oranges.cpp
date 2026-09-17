class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // first lets check all 2's and push to queue with t=0
        // apply bfs
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        queue<vector<int>> q; //{r,c,t}
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
              if(grid[i][j]==2)  q.push({i,j,0});
            }
        }
        while(!q.empty()){
            auto v =q.front();
            q.pop();
            ans = max(ans, v[2]);
            int t=v[2];
            //up
            if(v[0]>=1 && grid[v[0]-1][v[1]]==1){
                grid[v[0]-1][v[1]]=2;
                q.push({v[0]-1, v[1], t+1});
            }
            // left
            if(v[1]>=1 && grid[v[0]][v[1]-1]==1){
                grid[v[0]][v[1]-1]=2;
                q.push({v[0], v[1]-1, t+1});
            }
            // right
            if(v[1]<m-1 && grid[v[0]][v[1]+1]==1){
                grid[v[0]][v[1]+1]=2;
                q.push({v[0], v[1]+1, t+1});
            }
            if(v[0]<n-1 && grid[v[0]+1][v[1]]==1){
                grid[v[0]+1][v[1]]=2;
                q.push({v[0]+1, v[1], t+1});
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++) if(grid[i][j]==1) return -1;
        }
        return ans;
    }
};
class Solution {
public:
    
    int find(int x, vector<int> &par){
        if(par[x]==x) return x;
        return par[x] = find(par[x], par);
    }
    void unionByRank(int u, int v, vector<int>& rank, vector<int>& par){
        int paru =  find(u, par);
        int parv = find(v, par);

        if(rank[paru]==rank[parv]){
            rank[paru]++;
            par[parv] = paru;
        }else if(rank[paru]>rank[parv]){
            par[parv] = paru;
        }else par[paru] = parv;
     }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> rank(n,0);
        vector<int> par(n);
        for(int i=0; i<n; i++){
            par[i]=i;
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(isConnected[i][j]==1){
                    unionByRank(i,j, rank, par);
                }
            }
        }
        unordered_set<int> s;
        for(int ele: par) {
            int parele = find(ele,par);
            if(!s.count(parele)) s.insert(parele);}
        return s.size();
    }
};
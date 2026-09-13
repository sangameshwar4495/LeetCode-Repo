class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int,int>> A;
        vector<pair<int,int>> B;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(img1[i][j]==1) A.push_back(make_pair(i,j));
                if(img2[i][j]==1) B.push_back(make_pair(i,j));
            }
        }
        // unordered_map<vector<int>, int> m; requires custom hast funtion
        vector<vector<int>> cnt(2*n, vector<int>(n*2, 0));
        int ans = 0;
        for(auto a: A){
            for(auto b: B){
                int dx = a.first - b.first +n;
                int dy = a.second - b.second +n;
                ans = max(ans, ++cnt[dx][dy]) ;
            }
        }
        return ans;
    }
};
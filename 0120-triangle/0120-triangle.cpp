class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int i=0;
        int n=triangle.size();
        int ans = INT_MAX;
        for(int i=1; i<n; i++){
            for(int j=0; j<=i; j++){
                if(j==0){
                    triangle[i][j]+=triangle[i-1][j];
                }
                else if(j==i){
                    triangle[i][j]+=triangle[i-1][j-1];
                }
                else{
                    triangle[i][j]+=(min(triangle[i-1][j], triangle[i-1][j-1]));
                }
                if(i==n-1) ans=min(ans, triangle[i][j]);
            }
        }
        if(n==1) return triangle[0][0];
        return ans;
    }
};
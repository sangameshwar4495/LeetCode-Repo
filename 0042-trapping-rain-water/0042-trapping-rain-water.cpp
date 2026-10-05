class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> greater(n, -1);
        for(int i=1; i<n-1; i++){
            greater[i] = max(greater[i-1], height[i-1]);
        }
        for(int i=n-2; i>0; i--){
            greater[i] = min(greater[i], max(greater[i+1], height[i+1]));
        }
        int ans = 0;
        for(int i=1; i<n-1; i++){
            if(greater[i]>height[i]) ans+=(greater[i]-height[i]);
        }
        return ans;
    }
};
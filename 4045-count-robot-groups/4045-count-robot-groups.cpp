class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
        int ans = 1;
        int n = speed.size();
        int currSpeed = speed.back();
        for(int i=n-2; i>=0; i--){
            if(speed[i]<=currSpeed && position[i+1]-position[i] > distance){
                ans++;
                currSpeed = speed[i];
            }
        }
        return ans;
    }
};
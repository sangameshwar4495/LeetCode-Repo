class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int ans = 0;
        int gs = g.size();
        int ss = s.size();
        int i=0, j=0;
        while(i<ss && j<gs){
            if(s[i]>=g[j]){
                i++;
                j++;
                ans++;
            }else i++;
        }
        return ans;
    }
};
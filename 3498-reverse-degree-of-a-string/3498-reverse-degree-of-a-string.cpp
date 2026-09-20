class Solution {
public:
    int reverseDegree(string s) {
        int ans = 0;
        int idx = 1;
        for(char ch: s){
            ans+=((26-(ch-'a'))*idx);
            idx++;
        }
        return ans;
    }
};
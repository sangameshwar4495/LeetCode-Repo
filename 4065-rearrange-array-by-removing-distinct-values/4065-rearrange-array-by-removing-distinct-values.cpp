class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans;
        map<int,int> m;
        for(int ele: nums){
            m[ele]++;
        }
        int n = nums.size();
        while(n>0)
        for(auto p: m){
            if(p.second>0){
                ans.push_back(p.first);
                m[p.first]--;
                n--;
            }

        }
        return ans;
    }
};
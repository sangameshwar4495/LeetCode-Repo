class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        vector<string> s(n);
        bool zero = true;
        for(int i=0; i<n; i++){
            s[i] = to_string(nums[i]);
            if(nums[i]!=0) zero = false;
        }
        if(zero) return "0";
        sort(s.begin(), s.end(),[](string& a, string &b){
            return a+b > b+a;
        });
        string ans;
        for(auto word:s){
            ans+=word;
        }
        return ans;
    }
};
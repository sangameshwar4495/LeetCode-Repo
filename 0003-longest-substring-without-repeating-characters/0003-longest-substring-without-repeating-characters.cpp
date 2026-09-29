class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> chars;
        int n = s.size();
        int l = 0;
        int ans = 0;
        for(int r=0; r<n; r++){
            while(chars.count(s[r])){
                chars.erase(s[l]);
                l++;
            }
            if(!chars.count(s[r])){ //doesn't exist - !
                chars.insert(s[r]);
                ans = max(ans, r-l+1);
            }
        }
        return ans;
    }
};
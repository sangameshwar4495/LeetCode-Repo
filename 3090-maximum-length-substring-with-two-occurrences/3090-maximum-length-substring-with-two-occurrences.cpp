class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char, int> freq;
        int n = s.size();
        int l = 0;
        int ans = 0;
        for(int r=0; r<n; r++){
            freq[s[r]]++;
            while(freq[s[r]]>2){
                freq[s[l]]--;
                l++;
            }
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};
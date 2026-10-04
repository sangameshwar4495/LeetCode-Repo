class Solution {
public:
    int characterReplacement(string s, int k) {
        // the issue i was getting solving the q was i was unable to chose the letter 
        // SOLVE MAX CONSECUTIVE ONES ||| first

        int n = s.size();
        unordered_set<char> st;
        for(char ch: s) st.insert(ch);
        int ans = 0;
        for(char ch: st){
            int l = 0; 
            int other = 0;
            for(int r=0; r<n; r++){
                if(s[r]!=ch) other++;
                while(other>k){
                    if(s[l]!=ch) other--;
                    l++;
                }
                ans = max(ans, r-l+1);
            }
        }
        return ans;
    }
};
/*{
        int l = 0;
        int ans = 0;
        int cnt = 0;
        int isnotsame = 0;
        char ch = s[0];
        for(int r=0; r<s.size(); r++){
            
            if(s[r]!=ch){
                isnotsame++;
            }else cnt++;
            while(isnotsame>k){
                if(s[l]==ch) cnt--;
                else isnotsame--;
                l++;
            }
            if(cnt==0) ch=s[l];
            ans = max(ans, r-l+1);
        }
        return ans;
}*/
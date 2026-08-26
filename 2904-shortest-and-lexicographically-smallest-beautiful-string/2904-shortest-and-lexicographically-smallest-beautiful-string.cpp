class Solution {
public:

    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int minL = n;
        int ones= 0;
        string ans = "";
        int l=0; 
        for(int r=0; r<n; r++){
            if(s[r]=='1') ones++;
            if(ones<k) continue;

            while(ones>k || s[l]=='0'){
                if(s[l]=='1') ones--;
                l++;
            }

            // ones==k
            if(minL>(r-l+1)){
                minL= r-l+1;
                ans =s.substr(l,r-l+1);
            }else if(minL==(r-l+1)){
                string curr = s.substr(l,r-l+1);  
                if(ans=="" || ans>curr) ans = curr;
            }
        }
        return ans;
    }
};
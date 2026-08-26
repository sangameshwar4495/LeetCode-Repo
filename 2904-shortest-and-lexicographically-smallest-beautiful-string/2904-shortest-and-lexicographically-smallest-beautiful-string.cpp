class Solution {
public:
    bool isSmall(string s1, string s2){
        if(s1.size()<s2.size()) return true;
        if(s1.size()>s2.size()) return false;
        for(int i=0; i<s1.size(); i++){
            if(s1[i]>s2[i]) return false;
            else if(s1[i]<s2[i]) return true;
        }
        return true;
    }
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
            if(minL>=(r-l+1)){
                minL= r-l+1;
                string currString = s.substr(l,r-l+1);
                cout<<"doing here\n"<<currString<<"\n";
                if(ans=="" || isSmall(currString,ans)) ans = currString;
            }
        }
        return ans;
    }
};
class Solution {
public:
    string intTobin(int n){
        string ans;
        for(int i=0; i<32; i++){
            ans = to_string(n%2)+ans;
            n/=2;
        }
        return ans;
    }
    int binToint(string& s){
        int ans = 0;
        int mul = 2;
        for(int i=1; i<31;  i++){
            if(s[i]=='1') ans+=mul;
            if(i!=30)mul*=2;
        }
        return ans;
    }
    int reverseBits(int n) {
        string binform = intTobin(n);
        cout<<binform<<endl;
        // reverse(binform.begin(), binform.end());
        // cout<<binform<<endl;
        int ans = binToint(binform);
        return ans;
    }
};
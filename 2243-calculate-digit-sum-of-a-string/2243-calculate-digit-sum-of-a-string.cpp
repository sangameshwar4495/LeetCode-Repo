class Solution {
public:
    string transform(string s, int k){
        string ans;
        int t=0, sum=0;
        for(int i=0; i<s.size(); i++){
            if(t==k){
                ans+=to_string(sum);
                sum = 0;
                t=0;
            }
            if(t<k){
                sum+=(s[i]-'0');
                t++;
            }
        }
        if(t!=0){
            ans+=to_string(sum);
        }
        return ans;
    }
    string digitSum(string s, int k) {
        while(s.size()>k){
            s = transform(s,k);
        }
        return s;
    }
};
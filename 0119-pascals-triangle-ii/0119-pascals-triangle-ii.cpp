class Solution {
public:
    int nCr(int n, int r){
        long long ans = 1LL;
        for(int i=0; i<r; i++){
            ans*=(n-i);
        }
        for(int i=0; i<r; i++){
            ans/=(r-i);
        }
        return ans;
    }
    vector<int> getRow(int rowIndex) {
        vector<int> v(rowIndex+1,1);
        long long val = 1;
        for(int i=1; i<rowIndex; i++){
            
            val*=(rowIndex-i+1);
            val/=i;
            v[i] = (int)val;
        }
        return v;
    }
};
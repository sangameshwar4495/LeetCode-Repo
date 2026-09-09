class Solution {
public:
    long long countCommas(long long n){
        long long cmp = 1000;
        long long ans = 0;

        while(n>=cmp){
            ans+=(n-cmp+1);
            cmp*=1000;
        }
        return ans;
    }
};
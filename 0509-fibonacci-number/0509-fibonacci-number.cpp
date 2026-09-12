class Solution {
public:
    int fib(int n) {
        //dpq2
        // if(n==0 || n==1) return n;
        // vector<int> dp(n+1, 0);
        // dp[1] = 1;
        // for(int i=2; i<=n; i++){
        //     dp[i] = dp[i-1]+dp[i-2];
        // }
        // return dp[n];


        if(n==0 || n==1) return n;

        int fibn_1 = 1;
        int fibn_2 = 0;
        int curr = 1;
        for(int i=2; i<=n; i++){
            curr = fibn_1+fibn_2;
            fibn_2 = fibn_1;
            fibn_1 = curr;
        }
        return curr;
    }
};
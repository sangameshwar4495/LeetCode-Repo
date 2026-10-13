class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> sq(n);
        for(int i=0; i<n; i++){
            sq[i]=nums[i]*nums[i];
        }
        sort(sq.begin(), sq.end());
        int i=0; 
        int j=n-1;
        long long sum=0;
        while(i<=j){
            if(i==j){
                sum+=sq[i];
                break;
            }
            sum+=(sq[j]-sq[i]);
            i++;
            j--;
        }
        return sum;
    }
};
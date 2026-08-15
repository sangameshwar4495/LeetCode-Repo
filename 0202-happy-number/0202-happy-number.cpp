class Solution {
public:
    bool isOnedigit(int n){
        if(n/10==0) return true;
        
        return false;
    }
    bool isHappy(int n) {
        while(n!=1){
            // sum of sq
            int temp = 0;
            while(n>0){
                temp+=((n%10)*(n%10));
                n/=10;
            }
            n = temp;
            if(n==1 || n==7) return true;
            if(isOnedigit(n)) return false;
        }
        return true;
    }
};
class Solution {
public:
    int noones(int n){
        int i = 0;
        int ans = 0;
        while(n>=(1<<i)){
            if(n&(1<<i)) ans++;
            i++;
        }
        return ans;
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [this](const int& a,const int& b){
            if(noones(a)<noones(b))return true;
            if(noones(a)==noones(b))return a<b;
            return false;
        });

      return arr;
    }
};
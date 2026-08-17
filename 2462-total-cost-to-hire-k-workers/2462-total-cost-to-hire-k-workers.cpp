class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        // building pq1 for c elements from beg
        // building pq2 for c elements from end
        priority_queue<int, vector<int>, greater<int>> pq1;
        priority_queue<int, vector<int>, greater<int>> pq2;
        int i=0; //i=0
        int j=costs.size()-1;//j=n-1
        long long ans = 0;
        while(k-->0){
            while(pq1.size()<candidates && i<=j){
                pq1.push(costs[i++]);
            }
            while(pq2.size()<candidates && i<=j){
                pq2.push(costs[j--]);
            }

            int min1 = pq1.size()>0 ? pq1.top(): INT_MAX;
            int min2 = pq2.size()>0 ? pq2.top(): INT_MAX;

            if(min1<=min2){
                ans+= min1;
                pq1.pop();
            }else{
                ans+=min2;
                pq2.pop();
            }
        }
        return ans;
    }
};
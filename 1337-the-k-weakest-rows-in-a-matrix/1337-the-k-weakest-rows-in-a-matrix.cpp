class Solution {
public:
    int countS(vector<int> v){
        int lo=0, hi=v.size()-1;
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            if(v[mid]==1){
                lo = mid+1;
            }else hi=mid-1;
        }
        return lo;
    }
    class Row{
        public: 
        int ones;
        int idx;
    
        Row(int ones, int idx){
            this->ones = ones;
            this->idx = idx;
        }
        bool operator < (const Row &obj) const{
            if(this->ones == obj.ones) return this->idx > obj.idx;
            return this->ones > obj.ones;
        }
    };
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<Row> rows;
        for(int i=0; i<mat.size(); i++){
            vector<int> v = mat[i];
            Row r = Row(countS(v), i);
            rows.push_back(r);
        }
        priority_queue<Row> pq(rows.begin(), rows.end());
        vector<int> ans;
        for(int i=0; i<k; i++){
            ans.push_back(pq.top().idx);
            pq.pop();
        }
        return ans;
    }
};
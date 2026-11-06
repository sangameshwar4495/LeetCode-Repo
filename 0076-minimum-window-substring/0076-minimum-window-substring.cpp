class Solution {
public:
    bool cmp(unordered_map<char,int>& m1, unordered_map<char,int> &m2){
        // check if all ele of m2 lie in m1
        for(auto p: m2){
            if(m1[p.first]<p.second){
                return false;
            }
        }
        return true;
    }
    string minWindow(string s, string t) {
        string ans = s;

        int ns = s.size();
        int nt = t.size();
        unordered_map<char,int> ms;
        unordered_map<char,int> mt;

        for(char ch: t) mt[ch]++;

        int l=0;
        // b a d a c
        bool isexist=false;
        for(int r=0; r<ns; r++){
            ms[s[r]]++;
            
            while(ms[s[l]] > mt[s[l]]){
                ms[s[l]]--;
                l++;
            }
            if(cmp(ms, mt)){
                isexist =true;
                if(ans.size()>(r-l+1)) ans = s.substr(l,r-l+1);
            }
        }
        if(!isexist) return "";
        return ans;
    }
};
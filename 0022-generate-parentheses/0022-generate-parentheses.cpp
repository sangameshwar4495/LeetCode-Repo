class Solution {
public:
    vector<string> ans;
    void helper(string w, int open, int close){
        if(open+close==0){
            ans.push_back(w);
            return;
        }
        if(open>0) helper(w+"(", open-1, close);
        if(close>0 && open<close) helper(w+")", open, close-1);
        return;
    }
    vector<string> generateParenthesis(int n) {
        helper("", n, n);
        return ans;
    }
};
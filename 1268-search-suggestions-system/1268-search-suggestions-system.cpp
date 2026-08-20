class Solution {
public:
    class Node{
    public:
        Node* children[26];
        bool isEnd;
        Node(){
            isEnd = false;
            for(int i=0; i<26; i++) children[i] = NULL;
        }
    };
    void dfs(Node* root, string &curr, vector<string>& sugg){
        if(sugg.size()==3) return;
        if(root->isEnd){
            sugg.push_back(curr);
        }
        for(int i=0; i<26; i++){
            if(root->children[i]){
                char ch = 'a'+i;
                curr.push_back(ch) ;
                dfs(root->children[i], curr, sugg);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> ans;

        Node* root = new Node();
        Node* temp;
        for(string word : products){
            temp = root;
            for(char ch: word){
                if(temp->children[ch-'a']==NULL){
                    temp->children[ch-'a'] = new Node();
                }
                temp = temp->children[ch-'a'];
            }
            temp->isEnd = true;
        }
        temp = root;
        string prefix;
        for(char ch: searchWord){
            int i = ch-'a';
            temp = temp->children[i];
            if(temp==NULL) break;
            vector<string> sugg;
            prefix+=ch;
            dfs(temp, prefix, sugg);
            ans.push_back(sugg);
        }
        ans.resize(searchWord.size());
        return ans;
    }
};
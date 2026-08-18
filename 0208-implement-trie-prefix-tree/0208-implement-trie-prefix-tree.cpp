class Node{
    public:
        unordered_map<char, Node*> children;
        bool isEnd;
        Node(){
            isEnd = false;
        }
};
class Trie {
    Node* root;
public:
    
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* temp = root;
        for(char ch: word){
            if(temp->children.count(ch)==0){
                temp->children[ch] = new Node();
            }
            temp = temp->children[ch];
        }
        temp->isEnd = true;
    }
    
    bool search(string word) {
        Node* temp = root;
        for(char ch: word){
            if(temp->children.count(ch)) temp = temp->children[ch];
            else return false;
        }
        return temp->isEnd;
    }
    
    bool startsWith(string prefix) {
        Node* temp = root;
        for(char ch: prefix){
            if(temp->children.count(ch)) temp = temp->children[ch];
            else return false;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
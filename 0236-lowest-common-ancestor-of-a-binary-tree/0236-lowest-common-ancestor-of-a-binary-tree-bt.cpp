/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool dfs(TreeNode* root, int p, vector<TreeNode*>& path){
        if(root==NULL) return false;
        path.push_back(root);
        if(root->val==p) return true;
        bool isleft = dfs(root->left, p, path);
        bool isright = dfs(root->right, p, path);
        if(!isleft && !isright){
            path.pop_back();
            return false;
        } 
        return true;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pathp;
        vector<TreeNode*> pathq;
        dfs(root, p->val, pathp);
        dfs(root, q->val, pathq);
        // for(auto n: pathp){
        //     cout<<n->val<<" ";
        // }cout<<endl;
        // for(auto n: pathq){
        //     cout<<n->val<<" ";
        // }cout<<endl;
        TreeNode* ans;
        for(int i=0; i<min(pathp.size(),pathq.size()); i++){
            if(pathp[i]->val!=pathq[i]->val) break;
            ans = pathp[i];
        }
        return ans;
    }
};
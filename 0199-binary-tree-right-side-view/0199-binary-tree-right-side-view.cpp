/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* root, int vd, map<int,int>& m){
        if(root==NULL) return;
        m[vd] = root->val;
        dfs(root->left, vd+1, m);
        dfs(root->right, vd+1, m);
    }
    vector<int> rightSideView(TreeNode* root) {

        map<int,int> m;
        dfs(root, 0, m);
        vector<int> ans;
        for(auto it: m){
            ans.push_back(it.second);
        }
        return ans;
    }
};
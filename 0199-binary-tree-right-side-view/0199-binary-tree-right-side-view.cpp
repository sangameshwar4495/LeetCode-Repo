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
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL) return {};
        queue<TreeNode*> q;
        q.push(root);
        unordered_map<int, int> m;
        int vd = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz-->0){
                TreeNode* curr = q.front();
                q.pop();
                m[vd] = curr->val;
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            vd++;
        }
        vector<int> ans(m.size());
        for(auto p:m){
            ans[p.first] = p.second;
        }
        return ans;
    }
};
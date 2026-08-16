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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL) return {};
        deque<TreeNode*> q;
        q.push_front(root);
        vector<vector<int>> ans;
        bool reverse = false;
        while(!q.empty()){
            int sz = q.size();
            vector<int> curr;
            while(sz-->0){
                if(reverse){
                    TreeNode* top = q.back();
                    q.pop_back();
                    curr.push_back(top->val);
                    
                    if(top->right!=NULL) q.push_front(top->right);
                    if(top->left!=NULL) q.push_front(top->left);
                }else{
                    TreeNode* top = q.front();
                    q.pop_front();
                    curr.push_back(top->val);
                    if(top->left!=NULL) q.push_back(top->left);
                    if(top->right!=NULL) q.push_back(top->right);
                }
            }
                reverse = !reverse;
            ans.push_back(curr);
        }

        return ans;
    }
};
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
    bool dfs(TreeNode* root, TreeNode* min, TreeNode* max){
        if(root==NULL) return true;
        // if there is a min val the should have and curr val is < min, then not bal
        if(min!=NULL and root->val <= min->val) return false;
        if(max!=NULL and root->val >= max->val) return false;

        bool lt = dfs(root->left, min, root);
        bool rt = dfs(root->right, root, max);

        return lt && rt;
    }
    bool isValidBST(TreeNode* root) {
        return dfs(root, NULL, NULL);
    }
};
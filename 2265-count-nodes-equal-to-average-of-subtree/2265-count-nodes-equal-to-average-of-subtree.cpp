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
    int ans = 0;
    pair<int,int> post(TreeNode* root){
        if(root==NULL) return make_pair(0,0);
        auto pleft = post(root->left);
        auto pright = post(root->right);
        int sum = pleft.first + pright.first + root->val;
        int cnt = (pleft.second+pright.second)+1;
        if(sum/cnt == root->val) ans++;

        return make_pair(sum, cnt);
    }
    int averageOfSubtree(TreeNode* root) {
        post(root);
        return ans;
    }
};
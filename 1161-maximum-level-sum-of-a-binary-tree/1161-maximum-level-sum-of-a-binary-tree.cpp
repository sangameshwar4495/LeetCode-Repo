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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        long long maxSum = INT_MIN;
        int maxLevel = 0;
        int currLevel = 0;
        while(!q.empty()){
            int sz = q.size();
            long long currSum = 0;
            currLevel++;
            while(sz--){
                TreeNode* node = q.front();
                q.pop();
                currSum+=node->val;
                if(node->left!=NULL){
                    q.push(node->left);
                }
                if(node->right!=NULL) q.push(node->right);
            }
            if(currSum>maxSum){
                maxSum = currSum;
                maxLevel = currLevel;
            }
        }
        return maxLevel;
    }
};
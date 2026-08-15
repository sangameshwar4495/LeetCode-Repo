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
    TreeNode* InOrderS(TreeNode* root){
        while(root->left!=NULL){
            root = root->left;
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL;
        if(root->val < key){
            root->right = deleteNode(root->right, key);
        }else if(root->val > key){
            root->left = deleteNode(root->left, key);
        }else{ // val == key
            if(root->left==NULL && root->right==NULL){
                delete root;
                return NULL;
            }else if(root->left==NULL || root->right==NULL){
                return root->left==NULL? root->right:root->left;
            }else{// right and left both exists
                TreeNode* InS = InOrderS(root->right);
                root->val = InS->val;
                root->right =  deleteNode(root->right, InS->val);
                return root;
            }
        }
        return root;
    }
};
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
    int solve(TreeNode* root){
        if(root==NULL){
            return 0;
        }

        int l=solve(root->left);
        if(l==-1){
            return -1;
        }
        int r=solve(root->right);
        if(r==-1){
            return -1;
        }

        if(abs(l-r)>1){
            return -1;
        }

        return 1+ max(l, r);
    }

    bool isBalanced(TreeNode* root) {
        return solve(root)!=-1;
    }
};

//---------------------------------------------------------
/* 1. We will calculate the height of each subtree and if the difference in height bof left and right subtree is greater than 1 then we return -1. */

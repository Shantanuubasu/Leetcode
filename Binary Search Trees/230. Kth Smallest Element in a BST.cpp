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
    void inorder(TreeNode* root, int k, int &c, int &ans){
        if(!root){
            return;
        }
        inorder(root->left, k, c, ans);
        c++;
        if(k==c){
            ans=root->val;
            return;
        }
        inorder(root->right, k, c, ans);
    }

    int kthSmallest(TreeNode* root, int k) {
        int c=0;
        int ans=0;
        inorder(root, k, c, ans);
        return ans;
    }
};

//---------------------------------------------------------------------------------
/* 1. We will implement inorder traversal as it traverses in increasing order.
2. When the count becomes equal to k then we return the ans. */

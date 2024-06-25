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
    int sum=0;
    
    TreeNode* convertBST(TreeNode* root) {
        ios_base::sync_with_stdio(false);

        if(root==NULL){
            return NULL;
        }
        convertBST(root->right);
        sum+=root->val;
        root->val=sum;
        convertBST(root->left);
        return root;
    }
};

//---------------------------------------------------------
/* 1. Take a sum global variable to keep track of sum of values of nodes.
2. Now we will apply reverse inorder, so we will first go to the right subtree and add its value to the sum and then update node value to sum.
3. Then we will go to the left subtree and repeat the process.
4. Finally return root. */

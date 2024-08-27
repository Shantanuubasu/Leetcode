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
    int solve(TreeNode* root, int &maxi){
        if(root==NULL){
            return 0;
        }

        int l=solve(root->left, maxi);
        int r=solve(root->right, maxi);

        maxi=max(maxi, l+r);

        return 1+max(l, r);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int maxi=0;
        solve(root, maxi);
        return maxi;
    }
};

//-------------------------------------------------------------
/* 1. To find the diameter of the tree we can find the height of left subtree and right subtree of a node.
2. Then the maximum of maxi or l+r will be the maxi value.
3. Finally, return maxi. */

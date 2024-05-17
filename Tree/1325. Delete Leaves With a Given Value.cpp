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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(root==NULL){
            return NULL;
        }
        root->left=removeLeafNodes(root->left,target);
        root->right=removeLeafNodes(root->right,target);

        if(root->left==NULL && root->right==NULL && root->val==target){
            return NULL;
        }

        return root;
    }
};

//-------------------------------------------------------------------------------------
/* 1. We will solve this using DFS, so we will move to the left of the tree.
2. Then we will solve for the right subtree.
3. We will check for leaf nodes, meaning having both left and right pointer as NULL and having its value equal to the target value. Then we will return NULL for that node.
4. Otherwise, return the root which is the node itself. */

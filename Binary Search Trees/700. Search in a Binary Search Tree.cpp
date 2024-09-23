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
    

    TreeNode* searchBST(TreeNode* root, int val) {
        if(root==NULL || root->val==val){
            return root;
        }

        if(val<root->val){
            return searchBST(root->left, val);
        }
        
        return searchBST(root->right, val);
    }

    
};

//---------------------------------------------------------------------
/* 1. If the root is NULL or root's val is same as val then return root.
2. If the val of root's val is less than given val then search the left subtree.
3. Else, search the right subtree. */

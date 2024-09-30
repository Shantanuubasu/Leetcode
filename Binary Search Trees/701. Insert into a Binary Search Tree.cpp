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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL){
            return new TreeNode(val);
        }

        TreeNode* t=root;

        while(true){
            if(t->val<val){
                if(t->right!=NULL){
                    t=t->right;
                }
                else{
                    t->right=new TreeNode(val);
                    break;
                }
            }
            else{
               if(t->left!=NULL){
                    t=t->left;
                }
                else{
                    t->left=new TreeNode(val);
                    break;
                } 
            }
        }

        return root;
    }
};

//---------------------------------------------------------------
/* 1. If the root is NULL then return the node with value as val.
2. Otherwise, traverse in bst and if node's val is less than val then check if node's right is not null then move to right.
3. Else, assign val to node's right.
4. Similarly, do for left.
5. Finally, return root. */

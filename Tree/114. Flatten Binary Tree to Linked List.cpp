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
    void flatten(TreeNode* root) {
        TreeNode* temp=root;
        while(temp){
            TreeNode* right=temp->right;
            if(temp->left!=NULL){
                TreeNode* left=temp->left;
                temp->left=NULL;
                flatten(left);
                temp->right=left;
                while(left->right!=NULL){
                    left=left->right;
                }
                left->right=right;
            }
            temp=right;
        }

    }
};

//--------------------------------------------------------
/* 1. We assign temp as root and will go on traversing till temp is not null.
2. Take the right node as right and check if temp->left is not null then take left node as left and temp->left as null.
3. Now call flatten() with left as parameter and assign temp->right as left.
4. Traverse till left->right is not null and make left->right as right.
5. Now make temp as right. */

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
    int getRightTreeLowest(TreeNode* root){
        TreeNode* t=root->right;
        while(t->left!=NULL){
            t=t->left;
        }

        return t->val;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL){
            return NULL;
        }

        if(root->val>key){
            root->left=deleteNode(root->left, key);
        }
        else if(root->val<key){
            root->right=deleteNode(root->right, key);
        }
        else{
            if(root->left==NULL){
                TreeNode* rchild=root->right;
                delete(root);
                return rchild;
            }
            else if(root->right==NULL){
                TreeNode* lchild=root->left;
                delete(root);
                return lchild;
            }
            else{
                int n=getRightTreeLowest(root);
                root->val=n;
                root->right=deleteNode(root->right, n);

            }
        }

        return root;
    }
};

//-----------------------------------------------------------------
/* 1. If root is NULL then return NULL.
2. If the root's val is greater than key then move to the left.
3. If the root's val is lesser than key then move to the right.
4. When the key is found then if it is a leaf node or left child is NULL then the root will be replaced by root's right child.
5. If only the left child is available then it will be replaced by left child.
6. If both child are available then find the node with lowest value in right subtree and place it in root's place and then delete node for root's right.
7. Finally, return root. */

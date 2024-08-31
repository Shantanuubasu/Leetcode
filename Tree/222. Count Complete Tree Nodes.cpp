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

        int l=leftheight(root);
        int r=rightheight(root);

        if(l==r){
            return (1<<l)-1;
        }

        return 1+solve(root->left)+solve(root->right);
    }

    int leftheight(TreeNode* root){
        int c=0;
        while(root){
            c++;
            root=root->left;
        }

        return c;
    }

    int rightheight(TreeNode* root){
        int c=0;
        while(root){
            c++;
            root=root->right;
        }

        return c;
    }

    int countNodes(TreeNode* root) {
        return solve(root);
    }
};

//------------------------------------------------------------
/* 1. In solve(), if root is NULL then return 0.
2. Now find the height of left subtree and right subtree of root.
3. If left height and right height is same then we can say that it is a complete binary tree annd will have 2^n - 1 nodes.
4. Else, we add 1 and call solve function again for root's left and root's right.
5. To find the left subtree height, we have a function leftheight(), Where we count the number of nodes to the left of root.
6. Similarly. we can right height by moving towards right. */

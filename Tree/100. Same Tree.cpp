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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL){
            return true;
        }

        if(p==NULL || q==NULL){
            return false;
        }

        return ((p->val==q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
    }
};

//-------------------------------------------------------------------------------------------------------------------
/* 1. If p and q both are null then return true.
2. If p is null or q is null then return false.
3. Also return if p's value and q's value are same or not and call function with p's left and q's left and also call the function again for q's right and p' right. */

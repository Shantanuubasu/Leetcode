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
    void preorder(TreeNode* root, vector<int> &v){
        if(root!=NULL){
            v.push_back(root->val);
            preorder(root->left,v);
            preorder(root->right,v);
            
        }
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;
        preorder(root,v);
        return v;
    }
};

//----------------------------------------------------------------------
/* 1. In preorder the order of traversal is val|left|right.
2. So we first push the val in v.
3. Then we explore the left subtree.
4. Then we explore the right subtree. */

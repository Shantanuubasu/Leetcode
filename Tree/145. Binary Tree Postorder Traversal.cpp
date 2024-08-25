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
    void postorder(TreeNode* root,vector<int> &v){
        if(root!=NULL){
            postorder(root->left,v);
            postorder(root->right,v);
            v.push_back(root->val);
        }
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> v;
        postorder(root,v);
        return v;

    }
};


//-------------------------------------------------------------------------
/* 1. To find the post order traversal of a tree we first explore the left subtree.
2. Then we explore the right subtree.
3. After we have reached the leaf node then we will push the node value to v.
4. Finally, return v. */

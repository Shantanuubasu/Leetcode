// APPROACH - 1 - RECURSIVE 
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
    void inorder(TreeNode* root,vector<int> &v){
        if(root!=NULL){
            inorder(root->left,v);
            v.push_back(root->val);
            inorder(root->right,v);
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        inorder(root,v);
        return v;
    }
};

//--------------------------------------------------------------------
/* 1. In inorder the order of traversal is left|val|right.
2. First we explore the left subtree.
3. Then we push the node val to v.
4. Then we explore the right subtree.
5. Finally, return v. */
//--------------------------------------------------------------------------

//APPROACH - 2 - MORRIS TRAVERSAL

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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode* curr=root;

        while(curr!=NULL){
            if(curr->left==NULL){
                res.push_back(curr->val);
                curr=curr->right;
            }
            else{
                TreeNode* leftchild=curr->left;
                while(leftchild->right!=NULL){
                    leftchild=leftchild->right;
                }

                leftchild->right=curr;
                TreeNode* temp=curr;
                curr=curr->left;
                temp->left=NULL;
            }
        }

        return res;
    }
};

//--------------------------------------------------------------
/* 1. To traverse the binary tree in inorder morris traversal we will convert the tree into threaded binary tree. Where the last node is connected to the root.
2. Take curr as root and if curr's left is NULL then push curr's val to res and move curr to right.
3. If left is not NULL then take a leftchild pointer starting from left of curr and move it to extreme right.
4. Assign leftchild's right to curr and take a temp pointer and assign curr to it.
5. Now move curr to its left child and make temp's left as NULL.
6. Finally, return res. */

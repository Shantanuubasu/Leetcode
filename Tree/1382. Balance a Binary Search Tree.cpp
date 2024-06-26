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
    void inorder(TreeNode* root, vector<int>& v){
        if(root){
            inorder(root->left, v);
            v.push_back(root->val);
            inorder(root->right, v);
        }
    }

    TreeNode* bst(vector<int>& v, int start, int end){
        if(start>end){
            return NULL;
        }
        int mid=start+(end-start)/2;
        TreeNode* root=new TreeNode(v[mid]);
        root->left=bst(v, start, mid-1);
        root->right=bst(v, mid+1, end);
        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        ios_base::sync_with_stdio(false);

        vector<int> v;
        inorder(root, v);
        root=bst(v, 0, v.size()-1);
        return root;
    }
};

//----------------------------------------------------------
/* 1. To get the nodes in a sorted order we can do inorder traversal of tree.
2. In inorder traversal, we will push the node values in an array.
3. Now we will construct the bst again, where the middle element of the array will be the root of the tree and left and right elements to the mid will be the left and right subtree.
4. Finally, we return root of the tree. */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* solve(vector<int> preorder, int prestart, int preend,
                    vector<int> inorder, int instart, int inend,
                    unordered_map<int, int> &mp) {
        if (prestart > preend || instart > inend) {
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[prestart]);
        int inroot = mp[root->val];
        int leftnode = inroot - instart;

        root->left = solve(preorder, prestart + 1, preend + leftnode, inorder,
                           instart, inroot - 1, mp);
        root->right = solve(preorder, prestart + leftnode + 1, preend, inorder,
                            inroot + 1, inend, mp);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mp;
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }

        TreeNode* root = solve(preorder, 0, preorder.size() - 1, inorder, 0,
                               inorder.size() - 1, mp);

        return root;
    }
};

//------------------------------------------------------------------------------------------------
/* 1. First we map the elements of inorder to their indexes.
2. Then we call the solve function with parameters preorder, starting index of preorder, ending index of preorder, inorder, starting index of inorder, ending index of inorder and map.
3. In solve(), If the starting index of preorder exceeds ending index of preorder or starting index of inorder exceeds ending index of inorder then return NULL.
4. Now create the root which will the first element in the preorder.
5. Store the index of root in inorder in inroot.
6. Find the number of nodes to the left of root in leftnode.
7. Now solve for root's left hwere preorder starting index would be prestart+1 and ending index would be preend+leftnode and the starting of inorder would be inroot+1.
8. Similarly, solve for right where starting of preorder would be prestart+leftnode+1 and starting of inorder would be inroot+1.
9. Finally, return root. */

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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, long>> q;
        long maxi=0;
        q.push({root, 0});
        while(!q.empty()){
            long n=q.size();
            long st=q.front().second;
            long en=q.back().second;
            maxi=max(maxi, en-st+1);
            while(n--){
                pair<TreeNode*, int> it=q.front();
                q.pop();

                if(it.first->left){
                    q.push({it.first->left, (long)2*it.second +1});
                }

                if(it.first->right){
                    q.push({it.first->right, (long)2*it.second +2});
                }

            }
        }

        return maxi;
    }
};

//------------------------------------------------------------------------------------------
/* 1. We will do a bfs traversal on the tree, take a queue to store the node and its index with it.
2. Now take the index of the front of the queue and back of the queue update the maxi value with max of maxi or differnce of indexes.
3. Now we will pop all the nodes of the current level and push the nodes of the next level.
4. Finally, return maxi. */

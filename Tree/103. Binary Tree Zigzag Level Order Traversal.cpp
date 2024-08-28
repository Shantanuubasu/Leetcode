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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        bool flag=false;
        deque<TreeNode*> dq;
        TreeNode* node;
        if(root){
            dq.push_back(root);
        }

        while(!dq.empty()){
            int n=dq.size();
            vector<int> temp;
            while(n--){
                if(flag){
                    node=dq.back();
                    dq.pop_back();

                    if(node->right){
                        dq.push_front(node->right);
                    }
                    if(node->left){
                        dq.push_front(node->left);
                    }
                }
                else{
                    node=dq.front();
                    dq.pop_front();

                    if(node->left){
                        dq.push_back(node->left);
                    }
                    if(node->right){
                        dq.push_back(node->right);
                    }
                }

                temp.push_back(node->val);
            }

            ans.push_back(temp);
            flag=!flag;
        }

        return ans;
        
    }
};

//----------------------------------------------------------------------------
/* 1. We will keep a flag variable to keep alternating between rows.
2. Also, we will use a deque to perform the traversal.
3. If flag is true then we will pop elements from back of dq and push right and then left child node to front of dq.
4. If flag is false then pop from front of the dq and push left and right at the back of the dq.
5. Push the node's val to temp and after the inner while loop ends push them to ans and change the flag value.
6. Finally, return ans. */

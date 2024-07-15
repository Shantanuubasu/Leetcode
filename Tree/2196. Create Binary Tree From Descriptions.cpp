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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        ios_base::sync_with_stdio(false);

        unordered_map<int, TreeNode*> mp;
        unordered_set<int> s;

        for(vector<int> &v: descriptions){
            int p=v[0];
            int c=v[1];
            int isleft=v[2];

            if(mp.find(p)==mp.end()){
                mp[p]=new TreeNode(p);
            }

            if(mp.find(c)==mp.end()){
                mp[c]=new TreeNode(c);
            }

            if(isleft == 1) {  
                mp[p]->left = mp[c];
            } 
            else {
                mp[p]->right = mp[c];
            }

            s.insert(c);
        }

        for(vector<int> &v: descriptions){
            int p=v[0];
            if(s.find(p)==s.end()){
                return mp[p];
            }
        }

        return NULL;
    }
};

//---------------------------------------------------------------
/* 1. We will use a map to store the nodes and its corresponding values.
2. We will use set to store all the child nodes.
3. Now if we don't have a parent node then we will create one in the map.
4. We will do the same for child node.
5. Now we will check if isleft value is 1, if yes then we assign the left of parent to child. Else, we assign right.
6. Also, insert the child node in the set.
7. Now we check if any parent is missing from the set if yes then that will be our root and we return that node. */

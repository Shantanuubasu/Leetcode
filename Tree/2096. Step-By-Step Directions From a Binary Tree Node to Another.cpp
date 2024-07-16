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
    bool findPath(TreeNode* root, int startValue, string& str){
        if(root==NULL){
            return false;
        }

        if(root->val==startValue){
            return true;
        }

        str.push_back('L');
        if(findPath(root->left, startValue, str)){
            return true;
        }

        str.pop_back();

        str.push_back('R');
        if(findPath(root->right, startValue, str)){
            return true;
        }

        str.pop_back();

        return false;
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        ios_base::sync_with_stdio(false);

        string rootToSrc="";
        string rootToDest="";

        findPath(root, startValue, rootToSrc);
        findPath(root, destValue, rootToDest);

        int i=0, j=0;
        while(i<rootToSrc.length() && j<rootToDest.length() && rootToSrc[i]==rootToDest[j]){
            i++;
            j++;
        }

        string res="";

        for(int k=0; k<rootToSrc.length()-i; i++){
            res+='U';
        }

        for(int k=j; k<rootToDest.length(); k++){
            res+=rootToDest[k];
        }

        return res;
    }
};

//---------------------------------------------------------------------------------------------------------------------
/* 1. To find the path from source to destination we will first find the path from root to source and root to destination.
2. In findPath(), If the root is null then we return false.
3. If th root's value is equala to target value then we return true.
4. We push L to str and check if the target node is in the left of root or not, if yes then return true. Otherwise, pop back from str.
5. We will do same for right path.
6. Now after we have got both paths, we will find the lowest common ancestor, which is the most recent common parent for both the nodes.
7. This can be found out by traversing in both the strings and the element where both the strings don't match that is where is our lowest common ancestor.
8. Now we will add U to the res as long as the both string where common and add the remaining elements of rootToDest in res.
9. Finally, return res. */

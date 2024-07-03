/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        ios_base::sync_with_stdio(false);

        vector<vector<int>> mat(m, vector<int>(n, -1));
        int rowmin=0, colmin=0;
        int rowmax=m-1, colmax=n-1;

        ListNode* temp=head;
        while(temp){
            for(int i=colmin; i<=colmax && temp!=NULL; i++){
                mat[rowmin][i]=temp->val;
                temp=temp->next;
            }
            rowmin++;

            for(int i=rowmin; i<=rowmax && temp!=NULL; i++){
                mat[i][colmax]=temp->val;
                temp=temp->next;
            }
            colmax--;

            for(int i=colmax; i>=colmin && temp!=NULL; i--){
                mat[rowmax][i]=temp->val;
                temp=temp->next;
            }
            rowmax--;

            for(int i=rowmax; i>=rowmin && temp!=NULL; i--){
                mat[i][colmin]=temp->val;
                temp=temp->next;
            }
            colmin++;
        }

        return mat;

    }
};

//----------------------------------------------------------------------------
/* 1. Intialize a 2d matrix with initial values as -1.
2. Now do the traversal in the linked list and simulate the traversal in matrix.
3. Keep updating the matrix values.
4. Finally, return matrix. */

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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ios_base::sync_with_stdio(false);

        int pos=0;
        int firstcp=-1;
        int prevcp=-1;
        ListNode* back=head;
        ListNode* curr=head->next;
        int mindist=INT_MAX;
        vector<int> res={-1, -1};

        while(curr!=NULL && curr->next!=NULL){
            ListNode* front=curr->next;
            if((curr->val>back->val && curr->val>front->val) || (curr->val<back->val && curr->val<front->val)){
                if(firstcp==-1){
                    firstcp=pos;
                }
                else{
                    mindist=min(mindist, pos-prevcp);
                    res={mindist, pos-firstcp};
                }
                prevcp=pos;
            }

            pos++;
            back=curr;
            curr=front;
        }

        return res;
    }
};

//-----------------------------------------------------------------------------------------------------------------------------
/* 1. We will keep track of node number with pos, firstcp will store index of first critical point, prevcp will store the index of last occurrence of critical point.
2. mindist will keep track of minimum distance between two critical points.
3. Now we will traverse in the list, if the curr->val is less than or greater than its adjacent nodes then we will update mindist and res.
4. Finally, return res. */

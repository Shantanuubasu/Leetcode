class Solution {
public:
    bool validGroup(vector<int>& hand, int groupSize, int i, int n){
        int next=hand[i]+1;
        hand[i]=-1;
        ++i;
        int c=1;
        while(i<n && c<groupSize){
            if(hand[i]==next){
                next=hand[i]+1;
                hand[i]=-1;
                ++c;
            }
            ++i;
        }

        return c==groupSize;
    }

    bool isNStraightHand(vector<int>& hand, int groupSize) {
        ios_base::sync_with_stdio(false);

        int n=hand.size();
        sort(hand.begin(),hand.end());

        for(int i=0; i<n; i++){
            if(hand[i]>=0){
                if(!validGroup(hand,groupSize,i,n)){
                    return false;
                }
            }
        }

        return true;
    }
};

//------------------------------------------------------------------------------
/* 1. First we wil sort the hand array.
2. Then we check for every element which is greater than or equal to 0, if they could form a valid group.
3. In validGroup(), we take the next element needed and make hand[i]=-1 because we have used up that element in the other group.
4. Now check if there is any element available which is equal to next.
5. Keep checking till we reach end of the array or we complete the group size needed.
6. Check if the group formed is equal to group size needed.
7. If true then we start forming next group, otherwise we return false. */

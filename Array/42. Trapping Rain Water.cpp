class Solution {
public:
    int trap(vector<int>& height) {
        ios_base::sync_with_stdio(false);

        int l=0, r=height.size()-1;
        int lMax=0, rMax=0, ans=0;

        while(l<r){
            if(height[l]<=height[r]){
                if(lMax>height[l]){
                    ans+=lMax-height[l];
                }
                else{
                    lMax=height[l];
                }
                l+=1;
            }
            else{
                if(rMax>height[r]){
                    ans+=rMax-height[r];
                }
                else{
                    rMax=height[r];
                }
                r-=1;
            }
        }

        return ans;
    }
};

//------------------------------------------------------
/* 1. We take two pointer l and r, starting from 0th and (n-1)th index.
2. lMax and rMax keeps track of the largest element reached by l and r.
3. If the element at l is less than or equal to element at r then check if lMax is greater than element at l.
4. If yes, that means we can trap water so add their difference to ans.
5. Else, update the lMax value and increment l.
6. Do the same for r and then decrement r.
7. Finally, return ans. */

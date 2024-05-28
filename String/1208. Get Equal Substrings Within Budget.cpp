class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        ios_base::sync_with_stdio(false);

        int n=s.length();

        int i=0,j=0;
        int cost=0,ans=0;

        while(j<n){
            cost+=abs(s[j]-t[j]);

            while(cost>maxCost){
                cost-=abs(s[i]-t[i]);
                i++;
            }

            ans=max(ans,j-i+1);
            j++;
        }

        return ans;
    }
};

//--------------------------------------------------------------
/* 1. We will use sliding window approach, keep two pointer i and j.
2. Keep adding difference of element of both string at j to cost.
3. If cost becomes greater than maxCost move i to right and subtract the cost of ith elements.
4. Update ans with maximum
5. Finally return ans. */

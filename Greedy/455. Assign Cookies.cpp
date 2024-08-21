class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        int i=0, j=0;
        int c=0;
        while(i<g.size() && j<s.size()){
            if(g[i]<=s[j]){
                i++;
                j++;
                c++;
            }
            else{
                j++;
            }
        }

        return c;
    }
};

//--------------------------------------------------------------
/* 1. Sort both the arrays g and s.
2. Take two pointers i for g array and j for s array.
3. If the element at ith position in g array is less than or equal to jth element of s array then increment i, j and c.
4. Else, we increment j to find the cookie with suitable greed value.
5. Finally, return c. */

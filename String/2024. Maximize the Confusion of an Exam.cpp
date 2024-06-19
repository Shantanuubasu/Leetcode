class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        ios_base::sync_with_stdio(false);

        int i=0,j=0;
        int n=answerKey.length();
        int t=0,f=0;
        int ans=INT_MIN;
        while(j<n){
            if(answerKey[j]=='T'){
                t++;
            }
            else{
                f++;
            }

            if(min(t,f)>k){
                if(answerKey[i]=='T'){
                    t--;
                }
                else{
                    f--;
                }
                i++;
            }

            ans=max(ans,j-i+1);
            j++;
        }

        return ans;
    }
};

//-------------------------------------------------------------
/* 1. Take two pointer i and j, check element at j and increment t or f.
2. If the minimum of t or f becomes greater than k then move i pointer and decrement t or f accordingly.
3. Make ans as maximum of ans or j-i+1.
4. Finally, return ans. */

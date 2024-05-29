class Solution {
public:
    int numSteps(string s) {
        ios_base::sync_with_stdio(false);
        
        int n=s.length();
        int ans=0,carry=0;

        for(int i=n-1; i>=1; i--){
            if(((s[i]-'0')+carry)%2!=0){
                ans+=2;
                carry=1;
            }
            else{
                ans+=1;
            }
        }

        return ans+carry;
    }
};

//--------------------------------------------------------
/* 1. We will iterate in the string backwards.
2. We will check if after adding carry if the number is odd then we add 2 to answer because for odd numbers we are performing 2 operations, first adding 1 and then second removing the least significant bit.
3. If the number is even then we perform only one operation that is to remove the least significant bit.
4. Finally return ans + carry because the carry will contain the last operation. */

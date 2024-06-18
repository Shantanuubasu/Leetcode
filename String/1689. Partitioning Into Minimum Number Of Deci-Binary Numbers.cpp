class Solution {
public:
    int minPartitions(string n) {
        ios_base::sync_with_stdio(false);

        int maxi=INT_MIN;
        for(int i=n.length()-1; i>=0; i--){
            int num=n[i]-'0';
            maxi=max(maxi,num);
        }
        return maxi;
    }
};

//-------------------------------------------------------------
/* 1. We will handle each digit of the string individually.
2. Return the maximum digit in the string. */

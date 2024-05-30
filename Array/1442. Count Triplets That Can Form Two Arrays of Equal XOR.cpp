class Solution {
public:
    int countTriplets(vector<int>& arr) {
        ios_base::sync_with_stdio(false);

        vector<int> preXor;
        preXor.push_back(0);
        int Xor=0;
        for(int i=0; i<arr.size(); i++){
            Xor^=arr[i];
            preXor.push_back(Xor);
        }

        int ans=0;

        for(int i=0; i<preXor.size(); i++){
            for(int j=i+1; j<preXor.size(); j++){
                if(preXor[i]==preXor[j]){
                    ans+=j-i-1;
                }
            }
        }

        return ans;
    }
};

//--------------------------------------------------------------------
/* 1. We will find the prefix xor of the array.
2. Xor value initially is 0, so push it in the prefix xor array.
3. Now we iterate in the prefix xor array and if at the two indexes the value of xor is same then that means the element in between has xor as 0. So we add no. of possible subset of those indexes in the ans.
4. Finally return ans. */

class Solution {
public:
    int countPrimes(int n) {
        ios_base::sync_with_stdio(false);

        int arr[n+1];
        for(int i=2; i<=n; i++){
            arr[i]=1;
        }

        for(int i=2; i*i<=n; i++){
            if(arr[i]==1){
                for(int j=i*i; j<n; j+=i){
                    arr[j]=0;
                }
            }
        }

        int c=0;
        for(int i=2; i<n; i++){
            if(arr[i]==1){
                c++;
            }
        }

        return c;
    }
};

//----------------------------------------------------------
/* 1. We will take an array of size n+1 and mark every index as 1.
2. Now we will traverse from 2 to n and check if arr[i] is 1 then mark all its multiple as 0.
3. Now traverse in the array and count the indexes with 1.
4. Finally, return c. */

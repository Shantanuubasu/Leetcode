class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        ios_base::sync_with_stdio(false);

        int i=0,j=minutes;
        int unsatisfied=0;
        int n=grumpy.size();
        for(int i=0; i<minutes; i++){
            if(grumpy[i]==1){
                unsatisfied+=customers[i];
            }
        }

        int maxunsatisfied=unsatisfied;

        while(j<n){
            if(grumpy[j]==1){
                unsatisfied+=customers[j];
            }
            if(grumpy[i]==1){
                unsatisfied-=customers[i];
            }

            maxunsatisfied=max(maxunsatisfied,unsatisfied);
            i++;
            j++;
        }

        int satisfied=0;
        for(int i=0; i<n; i++){
            if(grumpy[i]==0){
                satisfied+=customers[i];
            }
        }

        return satisfied+maxunsatisfied;
    }
};

//---------------------------------------------------------------------------
/* 1. We will first calculate the number of unsatisfied customers in first window.
2. Now we will calculate the maximum unsatisfied customers in subsequent windows.
3. Now we will calculate total satisfied customers.
4. Finally, return the addition of satisfied customers and maximum unsatisfied customers. */

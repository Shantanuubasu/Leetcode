class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        std::ios_base::sync_with_stdio(false);
	    std::cin.tie(nullptr);

        sort(people.begin(),people.end());

        int i=0,j=people.size()-1;
        int ans=0;
        while(i<=j){
            long long int s=people[i]+people[j];
            if(s<=limit){
                ans++;
                i++;
                j--;
            }
            
            else{
                ans++;
                j--;
            }
        }

        return ans;
    }
};

//------------------------------------------------------------------
/* 1. We will use two pointers.
2. One will start from beginning of the array and other from end.
3. We will sort the array.
4. If sum of both the elements at their respective pointers is less than or equal to limit then increment ans and both the pointers.
5. Else increment ans and decrement j because the heavier people will need their own boats.
6. Finally return ans. */

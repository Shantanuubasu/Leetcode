class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        ios_base::sync_with_stdio(false);

        sort(seats.begin(),seats.end());
        sort(students.begin(),students.end());
        int ans=0;
        for(int i=0; i<seats.size(); i++){
            ans+=abs(seats[i]-students[i]);
        }

        return ans;
    }
};

//--------------------------------------------------------------------------------
/* 1. Sort both the arrays.
2. Add the absolute difference of elements of both the arrays in ans.
3. Return ans. */

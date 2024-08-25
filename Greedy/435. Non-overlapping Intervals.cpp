class Solution {
public:
    static bool compare(vector<int> a, vector<int> b){
        return a[1]<b[1];
    } 

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), compare);
        int c=0;
        int prev=intervals[0][1];
        for(int i=1; i<intervals.size(); i++){
            if(intervals[i][0]<prev){
                c++;
            }
            else{
                prev=intervals[i][1];
            }
        }

        return c;
    }
};

//---------------------------------------------------------------------------
/* 1. Sort the intervals based on their end times.
2. Now check if the start of interval is less than end of previous interval, if yes then increment c.
3. Else update prev with end time of current interval.
4. Finally, return c. */

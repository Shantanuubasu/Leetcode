class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n=students.size();
        int arr[2]={0};

        for(int &i:students){
            arr[i]++;
        }

        for(int i=0; i<n; i++){
            int s=sandwiches[i];
            
            if(arr[s]==0){
                return n-i;
            }

            arr[s]--;
        }

        return 0;
    }
};

//-----------------------------------------------------------------------------------------------------------------
/* 1. We keep the count of students prefering `circle` and `square` sandwiches in the array `arr`.
2. We traverse in `sandwiches` array and decrease the count if any student get their sandwich.
3. If count of either student becomes `0` then we return `n-i`. */

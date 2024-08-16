class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int maxele=arrays[0][0];
        int minele=arrays[0][arrays[0].size()-1];
        int maxdist=0;

        for(vector<int> v:arrays){
            maxdist=max({maxdist, abs(maxele-v[0]), abs(minele-v[v.size()-1])});
            maxele=max(maxele, v[v.size()-1]);
            minele=min(minele, v[0]);
        }

        return maxdist;
    }
};

//-----------------------------------------------------------------------------------------------
/* 1. Intialize the maxele and minele with first element of first array and last element of first array.
2. Now iterate in every array and update maxdist as max of maxdist or maxele-v[0] or  minele-v[v.size()-1] .
3. Update maxele as max of maxele or last element of current array.
4. Update minele as min of minele or first element of the array.
5. Finally, return maxdist. */

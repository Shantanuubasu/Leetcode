class Solution {
public:
    int solve(vector<int> &v, int k, int idx){
        if(v.size()==1){
            return v[0];
        }

        int i=((idx+k-1)%v.size());

        v.erase(v.begin()+i);

        return solve(v, k, i);
    }

    int findTheWinner(int n, int k) {
        ios_base::sync_with_stdio(false);

        vector<int> v(n);
        int idx=0;

        for(int i=0; i<n; i++){
            v[i]=i+1;
        }

        return solve(v, k, idx);
    }
};

//-----------------------------------------------------------
/* 1. We have to delete every kth person from the circle, the kth person will change everytime a person is deleted.
2. We take a array of size n having n person.
3. In the solve(), the base case is when v's size is 1 then we return the only remaining person.
4. We calculate the index of the person to be deleted which is (idx+k-1)%v.size(). Where, idx is the person next to last deleted person and we find %v.size() of it because the list should be a circle.
5. So now we delete the ith person and call the solve() again with i. */

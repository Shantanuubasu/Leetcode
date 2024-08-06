class Solution {
public:
    int minimumPushes(string word) {
        vector<int> v(26);

        for(char ch:word){
            v[ch-'a']++;
        }

        sort(v.begin(), v.end(), greater<int>());

        int push=1,ans=0, cnt=0;
        for(int i=0; i<v.size(); i++){
            if(v[i]==0){
                break;
            }

            ans+=v[i]*push;
            cnt+=1;

            if(cnt%8==0){
                push+=1;
            }
        }

        return ans;
    }
};

//-------------------------------------------------------------------------
/* 1. Take a vector of size 26 and add the frequency of each element of word in v.
2. Now sort the v array in descending order/
3. Then we iterate in v and if at any point the frequency of an element becomes 0 then we break because we have reached the end of the string and all the elements are covered.
4. push keeps track of the number of push it takes to type in a element.
5. So we add the number of elements multiplied by the number of push it takes.
6. Increment cnt to track the number of unique keys.
7. If cnt becomes a multiple of 8 then we increment push because we only have 8 keys to assign elements. */

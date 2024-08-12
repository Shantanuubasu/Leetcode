class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp;
        int c=0, i=0, j=0;
        int minlen=INT_MAX, st=-1;

        for(int i=0; i<t.size(); i++){
            mp[t[i]]++;
        }

        while(j<s.size()){
            if(mp[s[j]]>0){
                c++;
            }
            mp[s[j]]--;

            while(c==t.size()){
                if(j-i+1<minlen){
                    minlen=j-i+1;
                    st=i;
                }

                mp[s[i]]++;
                if(mp[s[i]]>0){
                    c--;
                }
                i++;
            }
            j++;
        }

        return (st==-1) ? "" : s.substr(st, minlen);

    }
};

//------------------------------------------------------------------
/* 1. Take a map and store the elements of t with their frequencies.
2. Take two pointers i and j start both from 0.
3. minlen keeps track of minimum valid substring and st keeps track of starting position of minlen.
4. If jth element frequency is greater than 0 then increment c and decrement the jth element frequency.
5. If c becomes equal to t's size then it means we have got a valid substring.
6. Update minlen and st if the current valid substring is less than previous.
7. Also add the ith element to map and if it's count is more than 0 then decrement c. Also, increment i and j.
8. If in the end st is equal to -1 then return empty string.
9. Else, return the substring starting from st upto minlen. */

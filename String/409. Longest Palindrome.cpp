class Solution {
public:
    int longestPalindrome(string s) {
        ios_base::sync_with_stdio(false);

        unordered_map<int,int> mp;

        for(char &ch: s){
            mp[ch]++;
        }

        int sum_odd=0,sum_even=0;
        int count_odd=0;
        for(auto &it: mp){
            if(it.second%2!=0){
                sum_odd+=it.second-1;
                count_odd++;
            }
            else{
                sum_even+=it.second;
            }
        }
        int ans=sum_odd+sum_even;
        return sum_odd%2==0 && count_odd>0 ? ans+1 : ans;
    }
};

//------------------------------------------------------------------------
/* 1. Take a map and store the frequency of every element.
2. Now take the sum of even frequencies and take sum of odd frequencies by reducing it by 1 because we are only taking even occurrences for the palindrome.
3. Add both sums and check if sum of odd is even and count of odd is greater than 0 this helps in case if there is only 1 occurrence of an element then we can add that 1 occurence to construct palindrome.
4. Otherwise, return ans. */

class Solution {
public:
    long long wonderfulSubstrings(string word) {
        std::ios::sync_with_stdio(0);
        unordered_map<long long ,long long> mp;
        long long x_or=0;
        mp[0]=1;

        long long res=0;

        for(char &ch :word){
            int sft=ch-'a';
            x_or^=(1<<sft);
            res+=mp[x_or];

            for(char ch1='a'; ch1<='j'; ch1++){
                sft=ch1-'a';
                long long chk_sft=(x_or^(1<<sft));
                res+=mp[chk_sft];
            }

            mp[x_or]++;
        }

        return res;
    }
};

//-----------------------------------------------------------------------------------------
/* 1. We will assign binary values to characters from `a` to `j` like `0001`, `0010` and so on.
2. We will store frequency of these xor values in unordered_map `mp`.
3. We will add the value of frequency for even count of characters in `res`.
4. For odd counts, we will check for if the current xor value has occured or not.
5. Then add its frequency to `res`.
6. Finally return `res`. */

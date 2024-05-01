class Solution {
public:
    string reversePrefix(string word, char ch) {
        int ind=word.length();
        for(int i=0; i<word.length(); i++){
            if(ch==word[i]){
                ind=i;
                break;
            }
        }

        if(ind == word.length()){
            return word;
        }

        int x=0,y=ind;
        while(x<y){
            char temp=word[x];
            word[x]=word[y];
            word[y]=temp;
            x++;
            y--;
        }

        return word;
    }


};

//-----------------------------------------------------------------------------------
/* 1. First we find the position of `ch` in `word`.
2. If not found return `word`.
3. If found, then use two pointer `x` and `y`, `x` points at start of string `word` and `y` points at character `ch` in string `word`.
4. Keep exchanging the elements at `x` and `y` till `x < y`.
5. Return `word`. */

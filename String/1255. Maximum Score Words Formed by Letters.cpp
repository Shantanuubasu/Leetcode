class Solution {
public:
    void solve(vector<string>& words, vector<int>& score, int& maxscore, vector<int> freq, int i, int currscore){
        maxscore=max(maxscore,currscore);
        if(i>=words.size()){
            return;
        }

        int j=0;
        int tempscore=0;
        vector<int> tempfreq=freq;
        while(j<words[i].length()){
            char ch=words[i][j];
            tempscore+=score[ch-'a'];
            tempfreq[ch-'a']--;
            if(tempfreq[ch-'a']<0){
                break;
            }
            j++;
        }

        if(j==words[i].length()){
            solve(words,score,maxscore,tempfreq,i+1,currscore+tempscore);
        }

        solve(words,score,maxscore,freq,i+1,currscore);
    }

    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        ios_base::sync_with_stdio(false);

        vector<int> freq(26,0);
        for(char& ch:letters){
            freq[ch-'a']++;
        }

        int maxscore=INT_MIN;
        solve(words,score, maxscore,freq,0,0);
        return maxscore;
    }
};

//---------------------------------------------------------------------------------------------------------
/* 1. We will use a vector to store the count of each letter.
2. Then we will take a word one by one.
3. For each word we have two options - either to take it or not.
4. But first we will check if the word can be formed with the given and remaining letters.
5. If we then we take the word and add the score of the word to current score and move onto next word.
6. If we do not take the current word then we do not add its score to the current score and just move forward to the next word.
7. Keep on updating the maxscore value.
8. Finally return the maxscore. */

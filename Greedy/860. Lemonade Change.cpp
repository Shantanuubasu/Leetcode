class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five=0, ten=0;

        for(int i: bills){
            if(i==5){
                five++;
            }
            else if(i==10){
                if(five>0){
                    five--;
                    ten++;
                }
                else{
                    return false;
                }
            }
            else if(i==20){
                if(ten>0 && five>0){
                    five--;
                    ten--;
                }
                else if(five>=3){
                    five-=3;
                }
                else{
                    return false;
                }
            }

        }

        return true;

    }
};

//-------------------------------------------------------------------
/* 1. Take a five dollars counter and a ten dollars counter.
2. If bill is of 5 then increment 5.
3. If bill is of then we check if we have five dollar bill then we give it so decrement 5 and increment 10. Else, we return false.
4. If we get a 20 then we check can we give back a 10 and a 5 if yes decrement both.
5. Else we check do we have atleast 3 five if yes then decrement 5 by 3. else, return false.
6. If all the above conditions satisfy then return true. */

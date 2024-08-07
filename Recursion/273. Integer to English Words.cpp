class Solution {
public:
    string solve(int num, unordered_map<int, string> digits, unordered_map<int, string> tenToNineteen, unordered_map<int, string> tenToNinety){
        if(num<10){
            return digits[num];
        }

        if(num<20){
            return tenToNineteen[num];
        }

        if(num<100){
            return tenToNinety[num/10] + (num%10!=0 ? " "+digits[num%10] : ""); 
        }

        if(num<1000){
            return solve(num/100, digits, tenToNineteen, tenToNinety) + " Hundred" + ((num%100!=0) ? " " + solve(num%100,  digits, tenToNineteen, tenToNinety) : ""); 
        }

        if(num<1000000){
            return solve(num/1000,  digits, tenToNineteen, tenToNinety) + " Thousand" + (num%1000!=0 ? " "+solve(num%1000,  digits, tenToNineteen, tenToNinety) : ""); 
        }

        if(num<1000000000){
            return solve(num/1000000,  digits, tenToNineteen, tenToNinety) + " Million" + (num%1000000!=0 ? " "+solve(num%1000000,  digits, tenToNineteen, tenToNinety) : ""); 
        }

        return solve(num/1000000000,  digits, tenToNineteen, tenToNinety) + " Billion" + (num%1000000000!=0 ? " "+solve(num%1000000000, digits, tenToNineteen, tenToNinety) : ""); 

        
    }
    string numberToWords(int num) {
        if(num==0){
            return "Zero";
        }

        unordered_map<int, string> digits={
            {0, ""},
            {1, "One"},
            {2, "Two"},
            {3, "Three"},
            {4, "Four"},
            {5, "Five"},
            {6, "Six"},
            {7, "Seven"},
            {8, "Eight"},
            {9, "Nine"}
        };

        unordered_map<int, string> tenToNineteen={
            {10, "Ten"},
            {11, "Eleven"},
            {12, "Twelve"},
            {13, "Thirteen"},
            {14, "Fourteen"},
            {15, "Fifteen"},
            {16, "Sixteen"},
            {17, "Seventeen"},
            {18, "Eighteen"},
            {19, "Nineteen"},
        };

        unordered_map<int, string> tenToNinety={
            {1, "Ten"},
            {2, "Twenty"},
            {3, "Thirty"},
            {4, "Forty"},
            {5, "Fifty"},
            {6, "Sixty"},
            {7, "Seventy"},
            {8, "Eighty"},
            {9, "Ninety"}
        };

        return solve(num, digits, tenToNineteen, tenToNinety);
    }
};

//-------------------------------------------------------------------------------
/* 1. If the num is 0 then return 0.
2. Now we create 3 maps, first for digits 0 to 9, one for 10 to 19 and another for tens like ten twenty...etc.
3. Now we call the solve(), If num is less than 10 then return from digits map.
4. If the num is less than 20 then return from tenToNineteen map.
5. If num is less than 100 then return from tenToNinety for tenths place and for ones place get the string from digits map.
6. If the num is less than 1000 then call solve for hundredths place and add "hundred" and solve for tenths place onwards if it is not zero.
7. If the number is less than a million then solve for thousandth place, add "thousand" and solve for hundredths place onwards if it is not zero.
8. If the number is less than 1000 million then solve for millionth place, add "Million and solve for remaining places if it is not zero.
9. Finally, solve for billions and add "Billions" and solve for remaining places if not zero. */

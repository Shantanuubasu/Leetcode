class Solution {
public:
    string frequencySort(string s) {
        vector < pair<int, char>> freq(123, {0,0});
        int n = s.length();
        string ans = "";
        for (int i = 0; i < n; i++) {
            freq[s[i]] = { freq[s[i]].first + 1, s[i] };
        }

        sort(freq.rbegin(), freq.rend());

        for (auto i : freq) {
            ans += string(i.first, i.second);
        }

        return ans;
    }
};

//-------------------------------------------------------------------
/* # Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
So we have to print the element in decending order of its frequency in the given string. Here uppercase and lowercase letters are counted separately.

# Approach
<!-- Describe your approach to solving the problem. -->
So to start we will take an array with pair of int and char to keep track of freq of each element,
the size of this array would be 123 as ASCII value of 'z' is 122. So array would be of size n+1=122+1=123. 
Now take an empty string ans to store the answer. We will iterate through the string and we will increment the count of the character as it occurs. 
Now we will reverse sort the array to get the decending order. 
Now we will iterate through freq array and the element according to the number of times it appears to the ans string. */ 

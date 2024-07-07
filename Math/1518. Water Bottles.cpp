class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        return numBottles + (numBottles-1)/(numExchange-1);
    }
};

//------------------------------------------------------------------
/* 1. Initially we can consume all the numBottles.
2. Then we can exchange (numBottles-1)/(numExchange-1) bottles to get the final answer. */

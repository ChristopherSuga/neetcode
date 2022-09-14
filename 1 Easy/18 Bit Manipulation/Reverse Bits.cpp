/*
    Reverse bits of a given integer
    Ex. n = 10011100 -> 00111001 = 57

    Shift into result & shift out of n

    Time: O(1)
    Space: O(1)
*/

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        // loops through all 32 bits
        for (int i = 0; i < 32; i++) {
            //shift the bits of result to the left
            result <<= 1;
            //performs a bitwise or on n and bitwise 1
            result |= n & 1;
            //shifts n right by 1
            n >>= 1;
        }

        return result;
    }
};
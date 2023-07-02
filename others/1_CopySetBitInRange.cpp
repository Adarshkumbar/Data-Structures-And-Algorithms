// Copy Set Bits in Range
// Given two numbers X and Y, and a range [L, R] where 1 <= L <= R <= 31. You have to copy the set bits of 'Y' in the range L to R in 'X'. Return this modified X.

// Note: Range count will be from Right to Left & start from 1.

// I/P : X = 44, Y = 3 L = 1,  R = 5
// O/P : 47 


class Solution{
    public:
    int setSetBit(int x, int y, int l, int r){
        for( int i = l ; i <= r ; i++)
        {
            // check if set bit is present in perticular posi i
            if( (y&(1<<(i - 1))) != 0) // perform & oprn cuz 1 & 1 == 1
            {
                //  changing j bit in x 
                x = x|(1<<(i-1));  // | operation cuz 0 | 1 == 1
            }
        }
        return x ;
    }
};
//              How Many X's?
//  medium 

/*
Given two integers L, R, and digit X. Find the number of occurrences of X in all the numbers in 
the range (L, R) excluding L and R.

Example 1:

Input:
L=10, R=19, X=1
Output:
9
Explanation:
There are 9 1s (11, 12, 13, 14, 15, 16, 17, 18) in the numbers in the range (10,19).

Example 2:

Input:
L=18, R=81, X=9
Output:
7
Explanation:
There are 7 occurrences of the digit 9 in the numbers in the range (18,81).
*/
int countX(int L, int R, int X) {
        int cnt = 0 ;
        
        for(int i = L + 1 ; i <R; i++){
            int num = i ; 
            while( num != 0 ){
                if( num % 10   == X)
                    cnt++;

                num/= 10;
            }
        }
        return cnt;
  }
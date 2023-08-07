//       Solve the Sudoku
/*
Given an incomplete Sudoku configuration in terms of a 9 x 9  2-D square matrix (grid[][]), the task is to find a solved Sudoku. For simplicity, you may assume that there will be only one unique solution.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
Zeros in the grid indicates blanks, which are to be filled with some number between 1-9. You can not replace the element in the cell which is not blank.


Sample Sudoku for you to get the logic for its solution:



Example 1:

Input:
grid[][] = 
[[3 0 6 5 0 8 4 0 0],
[5 2 0 0 0 0 0 0 0],
[0 8 7 0 0 0 0 3 1 ],
[0 0 3 0 1 0 0 8 0],
[9 0 0 8 6 3 0 0 5],
[0 5 0 0 9 0 6 0 0],
[1 3 0 0 0 0 2 5 0],
[0 0 0 0 0 0 0 7 4],
[0 0 5 2 0 6 3 0 0]]
Output:
True
3 1 6 5 7 8 4 9 2
5 2 9 1 3 4 7 6 8
4 8 7 6 2 9 5 3 1
2 6 3 4 1 5 9 8 7
9 7 4 8 6 3 1 2 5
8 5 1 7 9 2 6 4 3
1 3 8 9 4 7 2 5 6
6 9 2 3 5 1 8 7 4
7 4 5 2 8 6 3 1 9
Explanation: 
There exists a valid Sudoku for the input grid, which is shown in output.
Example 2:

Input:
grid[][] = 
[[3 6 6 5 0 8 4 0 0],
[5 2 0 0 0 0 0 0 0],
[0 8 7 0 0 0 0 3 1 ],
[0 0 3 0 1 0 0 8 0],
[9 0 0 8 6 3 0 0 5],
[0 5 0 0 9 0 6 0 0],
[1 3 0 0 0 0 2 5 0],
[0 0 0 0 0 0 0 7 4],
[0 0 5 2 0 6 3 0 0]]
Output:
False
Explanation: 
There does not exists a valid Sudoku for the input grid, since there are two 6s in the first row. Which cannot replaced.
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


// } Driver Code Ends
class Solution 
{
    public:
    bool isValid(int num , int grid[9][9], int row , int col) {
        for( int i = 0 ; i < 9 ; i++){
            if( grid[row][i] == num )
                return false;
        }
        
        for( int i = 0 ; i< 9 ; i++){
            if(grid[i][col] == num)
                return false ;
        }
        
        int rr = row - row % 3 , cc =col -col % 3 ;
        
        for( int i = 0 ; i< 3 ; i++){
            for( int j = 0; j < 3 ; j++){
                if(grid[rr + i][cc + j] == num )
                    return false;
            }
        }
        return true;
    }
    //Function to find a solved Sudoku. 
    bool SolveSudoku(int grid[N][N])  
    { 
        for( int i = 0 ; i < 9 ; i++){
            for( int j = 0; j< 9 ; j++){
                if(grid[i][j] == 0){
                    for( int k = 1; k <= 9 ; k++){
                        if( isValid(k,grid , i , j)){
                            grid[i][j] = k ;
                            bool ans = SolveSudoku(grid);
                            
                            if( ans ) 
                                return true;
                            else// backtracking
                                grid[i][j] = 0 ;
                        }
                    }
                    return false;
                }
            }
        }
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        for( int i = 0 ; i < N ; i++ ){
            for( int j = 0 ; j < N ; j++){
                cout<<grid[i][j]<<" ";
            }
        }
    }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}
// } Driver Code Ends
//    Rotate Matrix ny 90 degree clockwise
// 1st transpose the matrix ----> row -> col and col-> row  
// 2nd step reverse each row of matrixstep reverse each row of matrix

//  since for each row we alter col no need to travel to last row i.e till n-2
//  and j starts from i+1 cuz i,i already in correct posi

class Solution
{   
    public:
    //Function to rotate matrix anticlockwise by 90 degrees.
    void rotateby90(vector<vector<int> >& matrix, int n) 
    { 
        // transposing the matrix
        for( int i  = 0 ; i < n-1 ; i ++){  // not go to LAST row cuz already sorted
            for( int j = i + 1 ; j < n ; j++)
                swap( matrix[i][j], matrix[j][i]);
        }

        //  reversing the rows 
        for(int i = 0 ; i < n ; i++){
            reverse( matrix[i].begin(), matrix[i].end());
        }
    } 
};
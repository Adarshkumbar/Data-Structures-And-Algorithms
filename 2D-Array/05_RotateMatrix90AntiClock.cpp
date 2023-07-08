//    Rotate Matrix ny 90 degree in Anti Clockwise

class Solution
{   
    public:
    //Function to rotate matrix anticlockwise by 90 degrees.
    void rotateby90(vector<vector<int> >& matrix, int n) 
    { 
    //    1. rotate each row 
    //    1. transpose the matrix
    
    
    //  reversing the rows 
        for(int i = 0 ; i < n ; i++){
            reverse( matrix[i].begin(), matrix[i].end());
        }
        // transposing the matrix
        for( int i  = 0 ; i < n-1 ; i ++){  // not go to LAST row cuz already sorted
            for( int j = i + 1 ; j < n ; j++)
                swap( matrix[i][j], matrix[j][i]);
        }
    } 
};
//          Print like a wave i.e sine 
//    logic ➡️➡️⬇️
//          ➡️➡️⬇️ 
//          ⬆️⬅️⬅️
//     1. if odd column  print bottom to top 
//     2. if even column print top to bottom 
#include<iostream>
using namespace std;
#include <vector>

vector <int> printSpiral(int Arr[][4] , int row , int col){
    
    int total = row*col; // total emts
    int count = 0;  // used to check if every emt has been traversed
    //  i.e shouldnt go out of bound

    vector<int> v;
    // indexes
    int firstRow = 0;
    int lastRow  = row - 1;
    int firstCol = 0;
    int lastCol  = col - 1;
   
    while( count < total ){
         // printing  first row
        for(int i = firstCol ; i <= lastCol && count < total ; i++){
            v.push_back(Arr[firstRow][i]);
            count++;
        }
        firstRow++;
       // printing  first column
        for(int i = firstRow ; i <= lastRow && count < total ; i++){
            v.push_back(Arr[i][lastCol]);
            count++;
        }
        lastCol--;
        // printing last row
        for( int i = lastCol ; i >= firstCol && count < total ; i--){
            v.push_back(Arr[lastRow][i]);
            count++;
        }
        lastRow--;
        // printing  last column
        for( int i = lastRow ; i >= firstRow && count < total ; i--){
            v.push_back(Arr[i][firstCol]);
            count++;
        }
        firstCol++;
    }
     return v;   
}

void display(int Arr[][4] , int n , int m) 
{
    cout<<" \n2D arrays is :"<<endl;
    for( int i = 0 ; i < n ; i++)
    {
        for ( int j = 0 ; j < m ; j++)
            cout<< Arr[i][j] << " ";
        cout<<"\n";
    }
}

int main(){
    int Arr[][4] ={ {1,2,3,4},{4,3,5,2},{9,8,7,6},{0,2,5,1} };
    display(Arr , 4 , 4);
    cout<<"\n\n";
    vector <int> v = printSpiral(Arr , 4 , 4);
     for ( int j = 0 ; j < v.size(); j++)
            cout<< v[j] << " ";
}
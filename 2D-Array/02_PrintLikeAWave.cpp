//          Print like a wave i.e sine 
//    logic ⬇️⬆️ ⬇️⬆️ ⬇️⬆️
//     1. if odd column  print bottom to top 
//     2. if even column print top to bottom 
#include<iostream>
using namespace std;
#include <vector>


vector <int> printWave( int Arr[][4] , int row , int col)
{
    vector <int> v;
    for(int j = 0 ; j < col ; j ++){
        if(  j&1 )  // IF ODD
        {   
            for(int i = row -1  ; i >=0 ; i-- )
            {
                // cout<<Arr[i][j] << " ";
                v.push_back(Arr[i][j]);
            }
        }
        else{ // If EVEN
            for(int i = 0 ; i < row ; i++)
               v.push_back(Arr[i][j]);         // cout<<Arr[i][j] << " "; 
        }
    }
    return v;
}

void display(int Arr[][4] , int n , int m) // passing col is mandatory else compiler wont understand that it it 2D array
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
    int temp;
    display(Arr , 4 , 4);
    cout<<"\n\n";
    vector <int> v = printWave(Arr , 4 , 4);
     for ( int j = 0 ; j < v.size(); j++)
            cout<< v[j] << " ";
}
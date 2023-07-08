//                  Binary Search In Matrix
//  WE KNOW THAT ... Matrix(2 D ARRAY) Represented as linear array only in memory .[   ....           ...         ...        .. ];
// since question says sorted .....WE can apply BS

//  s = 0 , e = row*col - 1  and mid = s + (e - s )/2
//  once we get mid as Index how to represent it as Arr[][] ?

// ->> RowIndex :- since there are fixed colums for every Row ...By  " mid / col "  (i.e colSize (i.e m)) we get row of that index 
//  ex. 3*3 matrix and index = 6 &  by mid/col = 6/3 we get "2" i.e rowIndex = 2 which is correct check below
//  rowIndex= 0 -> [0 , 1, 2] ,  rowIndex= 1 ->[3 , 4 , 5] ,  rowIndex= 2 ->[6, 7 ,8]

// ->>ColIndex :-Since col( i.e colSize(i.e m)) for every rowIndex is same and colIndex lies within [ 0 - (col-1) ].. [ex.3*3 colIndexes 0,1,2]this can be performed by " mid % col " (i.e colSize (i.e m))..
// ex. 3*3 matrix and index = 6 & by mid&col = 6%2 we get "0" i.e colIndex = 0 which is correct check below
// colIndex = 0 -> [0 , 1 , 2 ]
// colIndex = 1 -> [3 , 4 , 5 ]
// colIndex = 2 -> [6 , 7 , 8 ]
#include<iostream>
using namespace std;
bool binarySearch2D( int Arr[][3],int row , int col , int key){
    int s = 0;
    int e = row*col - 1 ;
    int mid = s + (e - s )/2 ;

    while( s <= e){
        // get value from  midIndex in terms of rows and colums
        int emt = Arr[ mid/col][ mid%col];  // this is midValue

        if( emt == key){
            return true;
        }
        if( key > emt){
            s = mid+1;
        }
        else{
            e = mid-1;
        }
        mid = s + (e - s )/2 ;
    }
    return false;
}

void display(int Arr[][3] , int n , int m) 
{
    cout<<"\n2D arrays is :"<<endl;
    for( int i = 0 ; i < n ; i++)
    {
        for ( int j = 0 ; j < m ; j++)
            cout<< Arr[i][j] << " ";
        cout<<"\n";
    }
}

int main(){
    int Arr[3][3];
    cout<<"\nEnter 3*3 Matrix:\n" ;
    for(int i = 0 ; i < 3 ; i++){
        for(int j = 0 ; j < 3 ; j++)
            cin>>Arr[i][j];
    }
    display(Arr,3,3);

    int key;
    cout<<"\nEnter key to be Found:";
    cin>>key;
    int ans = binarySearch2D(Arr,3,3,key);
    cout<<ans;
    ans ? cout<<"\nEmt found" : cout<<"\nEmt not found";
}
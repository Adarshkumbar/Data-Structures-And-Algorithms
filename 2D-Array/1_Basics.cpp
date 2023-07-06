//  2 D array
//  even though we visualise as n rows and m colums
//  but stores in single memory like array
#include<iostream>
using namespace std; 

// 1. funtion to SEARCH EMT IN 2D ARRAY
bool searchEmt(int Arr[][3] , int k ,int row , int col){
    for( int i = 0 ; i < row ; i++)
        for( int j = 0 ; j < col ; j++)
            if( k == Arr[i][j])
                return true;

    return false;
}

// 2. funtion to find SUM OF ROWS

void rowSum(int Arr[][3],int row , int col){
 
    for( int i = 0 ; i < row ; i++){
        int sum = 0;
        for( int j = 0 ; j < col ; j++){
            sum += Arr[i][j];
        }
        cout<<"\nSum of "<< i <<" th row :"<<sum;
    }
}

// 3. funtion to find SUM OF COLUMNS

void colSum(int Arr[][3],int row , int col){
    for( int i = 0 ; i < col ; i++){
        int sum = 0;
        for( int j = 0 ; j < row ; j++){
            sum += Arr[j][i];
        }
        cout<<"\nSum of "<< i <<" th column :"<<sum;
    }
}
// 4. Find Largest rowSum
int largestRowSum(int Arr[][3],int row , int col){
    int maxi = INT_MIN;
    int rowIndex = -1;
    for( int i = 0 ; i < row ; i++){
        int sum = 0;
        for( int j = 0 ; j < col ; j++){
            sum += Arr[i][j];
            if( sum > maxi){
                rowIndex = i;
                maxi = sum;
            }
        }
    }
     cout<<"\nMax sum is: "<<maxi<<endl;
     return rowIndex;
}

void display(int Arr[][3] , int n , int m) // passing col is mandatory else compiler wont understand that it it 2D array
{
    cout<<" \n2D arrays is :"<<endl;
    for( int i = 0 ; i < 3 ; i++)
    {
        for ( int j = 0 ; j < 3 ; j++)
            cout<< Arr[i][j] << " ";
        cout<<"\n";
    }
}

int main(){
    int Arr[3][3];
    
      
    cout<<"\nSize of array is:"<<vect.size()<<endl;
    //A. Taking inputs
    cout<<" Enter 3 * 3 emts"<<endl;
    for( int i = 0 ; i < 3 ; i++)
    {
        for ( int j = 0 ; j < 3 ; j++)
            cin>> Arr[i][j];
    }
    //B. Printing array
    display(Arr , 3, 3);


    //C. Searching emts in 2D array
    int key;
    cout<<"\nEnter key : ";
    cin>>key;
    if( searchEmt( Arr , key , 3 , 3  ) )  // array key row col
        cout<<"\nEmt found "<< endl;
    else    
         cout<<"\nEmt not found "<< endl;

    //D. Find Row Sum
    rowSum(Arr, 3 , 3);

    //E. Find Column Sum
    colSum(Arr, 3, 3);

    //F. Find Largest rowSum
    int rowIndex = largestRowSum(Arr, 3, 3);
    cout<<rowIndex<<" row    Largest sum";
}
//  logic used
//  start from arr1 ending and arr2 starting

#include<iostream>
using namespace std;
#include<vector>

void display( vector <int> v){

    int size = v.size();
    for(int i = 0 ; i < size ; i++ )
        cout<<v.at(i);
    cout<<endl;
}

void mergeSortedArrays( vector <int> &v1 , vector <int> &v2 , int n , int m ){
    int i = n - 1 ;
    int j = 0 ; 

    while( i >= 0 && j < m -1 ){
        if( v1[i] == v2[j])
            swap( v1[i],v2[j]);
        else  // this means both arrays are in correct order i.e emts of arr1 < arr2 emts
            break;      
        i--;
        j++;
    }
}


int main(){
    vector <int> v1;
    vector <int> v2;
    int n; // size of v1
    int m; // size of v2
    int temp;

    cout<<"Enter size of 1st Array: ";
    cin>>n;
    cout<<"Enter Emts of 1st Array: ";
    for(int i = 0 ; i < n ; i++)
    {
        cin>>temp;
        v1.push_back(temp);
    }

    cout<<"Enter size of 2nd Array: ";
    cin>>m;
    cout<<"Enter Emts of 2nd Array: ";
    for(int i = 0 ; i < n ; i++)
    {
        cin>>temp;
        v1.push_back(temp);
    }

    mergeSortedArrays( v1, v2 , n , m);

     cout<<"Sorted 1st array:\n";
    display( v1 );
    cout<<"Sorted 1st array:\n";
    display( v2 );
}
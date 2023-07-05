//1. compare i th emt of Arr1  with jth emt of  Arr2
//2. if Arr1[i] if small put in third array and i++ j++
//3. else put Arr[j] in third aray and j++ k++

#include<iostream>
#include<stdlib.h>

using namespace std;

void MergeSortedArrays(int Arr1[], int n, int Arr2[], int m, int Arr3[] ){  // n size of Arr1 . m size of Arr2 
    int i = 0 , j = 0 , k = 0 ;   // k for Arr3
    while( i < n && j < m)
    {
        if( Arr1[i] < Arr2[j])  // 1st array emt is small so put in 3rd Array v
            Arr3[k++] = Arr1[i++] ; 
        else
             Arr3[k++] = Arr2[j++] ;// 2nd  array emt is small so put in 3rd Array v
    }

    // Wkt there might be case that m > n or n > m so some emts will be left out we
    //  copy remaining emts in 3rd array by below code

    while (i < n)  // this shows whether there are some emts left in Arr1 
    {
       Arr3[k++] = Arr1[i++];
    }
    
     while (j < m)  // this shows whether there are some emts left in Arr2
    {
       Arr3[k++] = Arr2[j++];
    }

}

void Display(int * Arr, int size) {
    for(int i = 0 ; i < size  ; i++){
        cout<<" "<< Arr[i];
    }
}

int main()
{
    int Arr1[]= {1,3,5,7} ;
    int Arr2[]= {2,4,6,8} ;
    int Arr3[]= {0} ; 
     // OUTPUT SHOULD BE 1,2,3,4,5,6,7,8
    

    MergeSortedArrays( Arr1, 4, Arr2, 4, Arr3) ; // 2nd argument is size

    cout<<"\nReversed Array is : \n";

    Display(Arr3, 8) ;      // 2nd argument is size

    return 0 ;
}
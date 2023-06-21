// 1. Adaptive algo i.e less comparison compared to bubble and selection sort
// 2. just like card game....if new emt is greater than emt put right | else check left emts repeat
// 3. we are not swapping here but shifting posi of emts based on conditions

#include<iostream>
using namespace std;

int InsertionSort(int * arr , int n ){
    for(int i = 1 ; i < n ; i++)  // outer loop from 1 cuz we want to loop inner loop from i-1 so yeah
    {
        int temp = arr[i];   // temp will store emt to be compared with value ... i.e new emt 
        int j = i - 1 ;
        for( ; j >= 0 ; j-- ) // loop from i-1 to 0 
        {
             if (temp < arr[j])
             {
               arr[j+1] = arr[j];
             }
             else{
                 break ; // cuz left part will be already sorted
             }
        }
        // out of inner loop
        arr[j+1] = temp ; // j+1 cuz j will be moved to beginning of sorted part.... ex 2, 6, 7. temp = 3 so j = 0 here when we come out of loop
    }
}

int main()
{
    int Array[] = { 22 , 11, 22, 33, 5, 6 , 19};
    int n = 7; // size of above array 
    
    InsertionSort(Array , n);
    
    for (int i = 0; i < n; i++)
    {
       cout << ' '<< Array[i] << ' ' ;
    }
    
}
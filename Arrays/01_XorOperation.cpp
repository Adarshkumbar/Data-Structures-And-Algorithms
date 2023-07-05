// Performing xor operation on emts using array

#include<iostream>
#include<stdlib.h>

using namespace std;

int main()
{
    int a []= {1,2,1,4,5} ;
    int b = 0 ;
    for (int i = 0 ; i < 5; i++ )
    {
        cout<< a[i] << " xor "  << b << " = " ;
         b = a[i] ^ b ;
         cout<< b << endl;
     }
    cout<<"\n****************************\n";
    for (int i = 0 ; i < 5; i++ )
    {
        cout<< b << " xor "  << i << " = " ;
         b = b ^ i ;
         
         cout<< b << endl;
     }
    cout<<"\nAnswer is : "<<b;
}
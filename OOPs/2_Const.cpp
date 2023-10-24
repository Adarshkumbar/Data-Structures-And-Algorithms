#include<iostream>
using namespace std;

int main(){
    //  const variable -- need to initialise and cant reinitialise
    const int  i = 10; // or int const i= 10;
    cout<< i << endl;
   
//     const pointer
    int x = 111;
    const int * ptr = & i; 
    cout<<* ptr << " " << x << endl;

    ptr = & x; 
    x = 12;
    cout<<* ptr << " " << x << endl;
}
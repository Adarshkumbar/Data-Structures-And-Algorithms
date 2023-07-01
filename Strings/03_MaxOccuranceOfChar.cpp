// Task : find max occuring char from a string 
//  ex : test -> t 
// ex : hello -> l
//  logic used ... created array each index for each letter and 
//  increment that index value if the char matches ......ch  - 'a' gives number ex: z - a = 25 
#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;

char maxOccurrance(string str){
  
     // stores number which ch has been converted via ch - 'a' ex: z - a = 25 
    int Arr[26] = {0} ; //array where each index represents a letter from a - z
    for(int i = 0 ; i < str.length(); i++){
        char ch  = str[i]; //used to store every char of str
        int  number = ch - 'a' ; // ch to number conversion ex : a - a = 0 .... z - a = 25 etc
        Arr[number]++ ;   // just increment that characters  posi/ index ex : if z is char then Arr[25] -> 1 again z then 2 so on
    }

    //  now find max from array which is Max Occurance 
    int max = -1 , ans = 0; // ans stores index value
     for(int i = 0 ; i <26; i++){  // till 26 cuz need to check every posi i.e every char
       if( max < Arr[i])
       {
            ans = i;
            max = Arr[i];
       }
            
    }
    cout<<"--.>"<<ans;
    return  'a' + ans ;   // covert number back to char
}

int main(){
    string str; 
    cout<<"Enter a string :";
    cin>> str; 
    cout<<"\n Max Occured char from String is : " <<maxOccurrance(str);

    return 0;
}
//                      Stock buy and sell II

/*The cost of stock on each day is given in an array price[] of size n. Each day you may decide to either buy or sell the stock i at price[i], you can even buy and sell the stock on the same day, Find the maximum profit which you can get.

Note: You can only hold one stock at a time.

Example 1:

Input:
n = 4
a = {3, 4, 1, 5}
Output:
5
Explanation:
We can buy stock on day 1 (at price 3) and sell it on 
day 2 (at price 4) profit will be 4-3=1, 
We can buy another stock on day 3 (at price 1) and sell 
it on day 4 (at price 5) profit will be 5-1=4, 
which will give us maximum profit of 5.
*/
#include<bits/stdc++.h>
using namespace std;

class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


class Solution {
  public:
    int stockBuyAndSell(int n, vector<int> &prices) {
        int profit = 0 ; // profit initially 0
        
        //  loop through the days from day 1 to n-1
        
        for(int i = 1 ; i < n ; i++)
        {
      // instead of checking max profit we keep on adding profits ...we wont consider loss cuz ques says so
            if( prices[i] > prices[i-1])  
                profit += prices[i] - prices[i-1];
        }
        return profit;
    }
};

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        vector<int> prices(n);
        Array::input(prices,n);
        
        Solution obj;
        int res = obj.stockBuyAndSell(n, prices);
        
        cout<<res<<endl;
    }
}

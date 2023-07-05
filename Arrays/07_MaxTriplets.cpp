//              max triplet 
/*
You are given an array 'A' of length 'N'.

The goodness of the is defined as the maximum value of '(A[]-A[]) * A[k]'  where (1 <= '<'J'<'k' <= 'N') over all triplets of the array 'A'.

Find the goodness of the array. If the goodness of the

array is less than zero,

ex: ex input 7 13 17 10 20 13 24 28 14  out put is 98 
*/
long long maxTriplets(int n,vector<int> &a){
  
   int goodness = INT_MIN;
    for (int i = 0; i < n -2 ; i++) {  // n-2 cuz triplet 
        for (int j = i + 1; j < n-1; j++) {
             for (int k = j + 1; k < n; k++) {
                 goodness = max(goodness, (a[i] - a[j]) * a[k]);
             }
        }
  }
  return goodness >= 0 ? goodness : 0;
}

int main(){
    maxTriplets();
    return 0;
}
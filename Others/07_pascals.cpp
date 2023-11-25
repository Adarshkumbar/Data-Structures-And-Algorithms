//          Pascal Triangle
//  easy

/*
Given a positive integer N, return the Nth row of pascal's triangle.
Pascal's triangle is a triangular array of the binomial coefficients formed by summing up the elements of previous row.
*/
vector<long long> nthRowOfPascalTriangle(int n) {
      
       long long mod = 1000000007;
        vector<long long> al(n, 0);

        al[0] = 1;

        for (int i = 0; i < n - 1; i++) {
            for (int j = n - 1; j >= 1; j--) {
                al[j] = (al[j] % mod + al[j - 1] % mod) % mod;
            }
        }
        return al;
}
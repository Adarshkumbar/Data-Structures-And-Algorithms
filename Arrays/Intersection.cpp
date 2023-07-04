
#include <bits/stdc++.h>
using namespace std;
#include<set>

class Solution {
   
  public:
   
    int NumberofElementsInIntersection(int a[], int b[], int n, int m) {
    // Create two unordered sets
    unordered_set<int> s1, s2;
    int count = 0;
    // Insert elements of first array into first set
    for (int i = 0; i < n; i++) {
        s1.insert(a[i]);
    }
    
    // Check if elements of second array are present in first set
    for (int i = 0; i < m; i++) {
        if (s1.find(b[i]) != s1.end()) {
            // If element is present, insert it into second set
            s2.insert(b[i]);
        }
    }
    
    // Print elements of second set
    for (auto it = s2.begin(); it != s2.end(); it++) {
        count ++ ;
    }
    return count ;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[n], b[m];
        for (int i = 0; i < n; i++) cin >> a[i];

        for (int i = 0; i < m; i++) cin >> b[i];
        Solution ob;
        cout << ob.NumberofElementsInIntersection(a, b, n, m) << endl;
    }
    return 0;
}

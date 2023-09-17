//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    private: 
        void solve(vector<int> A , vector<int> output, int index ,vector<vector<int> >& ans){
        // Base Case
            if( index >= A.size()){
                ans.push_back(output);
                return ;
            }
        // exclude 
            solve(A ,output , index+1 , ans );
        
        // include
            int ele = A[index];
            output.push_back(ele);
            solve(A ,output , index+1 , ans ); 
        }
    public:
    vector<vector<int> > subsets(vector<int>& A)
    {
        vector<vector<int> > ans;
        vector<int> output;
        solve(A ,output , 0 , ans );
        sort(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin >> t;
// Partition Equal Subset Sum

	// while (t--)
	// {
		int n, x;
		cin >> n;

		vector<int> array;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			array.push_back(x);
		}
        
        
        Solution ob;
		vector<vector<int> > res = ob.subsets(array);

		// Print result
		for (int i = 0; i < res.size(); i++) {
			for (int j = 0; j < res[i].size(); j++)
				cout << res[i][j] << " ";
			cout << endl;
		}

		
	// }

	return 0;
}
// } Driver Code Ends
//                            Top K Frequent Elements in Array 
// easy
/*
Given a non-empty array nums[] of integers of length N, find the top k elements which have the highest frequency in the array. If two numbers have same frequencies, then the larger number should be given more preference.

Example 1:

Input:
N = 6
nums = {1,1,1,2,2,3}
k = 2
Output: {1, 2}
Example 2:

Input:
N = 8
nums = {1,1,2,2,3,3,3,4}
k = 2
Output: {3, 2}
Explanation: Elements 1 and 2 have the
same frequency ie. 2. Therefore, in this
case, the answer includes the element 2
as 2 > 1.
*/
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> topK(vector<int>& nums, int k) {
         int N = nums.size();

        unordered_map<int, int> mp;
        for (int i = 0; i < N; i++)
            mp[nums[i]]++;

        priority_queue<pair<int, int> > pq;

        for (auto x : mp) {//N
            pq.push({ x.second, x.first });  //logN
        }
    //     while (!pq.empty()) {
    // cout << pq.top().first << " " << pq.top().second << endl;
    // pq.pop();
    // }
    // freq : ele
    // 3 2
    // 3 1
    // 1 3
      
        vector<int> ans;

        for (int i = 1; i <= k; i++) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};


//{ Driver Code Starts.
int main() {

    int n;
    cin >> n;
    vector<int> nums(n);
    for (auto &i : nums) cin >> i;
    int k;
    cin >> k;
    Solution obj;
    vector<int> ans = obj.topK(nums, k);
    for (auto i : ans) cout << i << " ";
    cout << "\n";
}
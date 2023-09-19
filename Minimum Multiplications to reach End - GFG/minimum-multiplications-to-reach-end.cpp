//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        int MOD = 1e5;
        queue<pair<int,int>> q;
        q.push({0,start});
        
        vector<int> dist(1e5,1e9);
        dist[start] = 0;
             if(start == end) return 0;
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            
            int steps = it.first;
            int node = it.second;
            
            for(auto itr:arr){
                int num = (itr*node)%MOD;
                if (steps + 1 < dist[num])
                {
                    dist[num] = steps + 1;

                    // Whenever we reach the end number
                    // return the calculated steps
                    if (num == end)
                        return steps + 1;
                    q.push({steps+1, num});
                }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends
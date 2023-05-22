//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    int rec(int i1, int i2, string s1, string s2, int x, int y, vector<vector<int>>& dp){
        if(i1==-1 || i2==-1) return 0;
        if(dp[i1][i2]!=-1) return dp[i1][i2];
        if(s1[i1]==s2[i2])  return dp[i1][i2] = 1 + rec(i1-1,i2-1,s1,s2,x,y,dp);
        return dp[i1][i2] = max(rec(i1-1,i2,s1,s2,x,y,dp), rec(i1,i2-1,s1,s2,x,y,dp));
        
    }
    int lcs(int x, int y, string s1, string s2)
    {
        vector<vector<int>> dp(x,vector<int>(y,-1));
        return rec(x-1,y-1,s1,s2,x,y,dp);
    }
};


//{ Driver Code Starts.
int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends
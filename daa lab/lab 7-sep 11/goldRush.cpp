//sri rama jayam 
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
      int fun(int i,int j,vector<int> &A,vector<vector<int>> &dp)
    {
        if(i>j)
            return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int l=A[i]+min(fun(i+2,j,A,dp),fun(i+1,j-1,A,dp));
        int r=A[j]+min(fun(i+1,j-1,A,dp),fun(i,j-2,A,dp));
        return dp[i][j]=max(l,r);
    }
    
    int maxCoins(vector<int>&A,int n)
        {   
            vector<vector<int>> dp(n,vector<int>(n,-1));
            return fun(0,n-1,A,dp);
    }
};

int main()
{
    
}
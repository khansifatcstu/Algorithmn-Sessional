#include<bits/stdc++.h>
using namespace std;


int knapsack(int W,vector<int> &val,vector<int> &wt)
{
    int n=wt.size();
    vector<vector<int>> dp(n+1,vector<int> (W+1,0));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=W;j++)
        {
            int notpick=dp[i-1][j];
            int pick=0;
            if(wt[i-1]<=j)
            {
                pick = val[i-1]+dp[i-1][j-wt[i-1]];
            }
          dp[i][j]=max(notpick,pick);
        }
    }
    return dp[n][W];
}


int main()
{
    vector<int> val = {1, 2, 3};
    vector<int> wt = {4, 5, 1};
    int W=4;
    cout<<knapsack(W,val,wt)<<endl;
    return 0;
}


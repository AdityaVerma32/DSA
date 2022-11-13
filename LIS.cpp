#include<bits/stdc++.h>
using namespace std;



int solution1(int i,int last,vector<int> vi,int n,vector<vector<int>> &dp)
{
    if(i==n)
    return 0;

    if(dp[i][last+1]!=-1)
    return dp[i][last+1];

    int len=solution1(i+1,last,vi,n,dp);
    if(last==-1||vi[last]<vi[i])
    len=max(len,1+solution1(i+1,i,vi,n,dp));

    return dp[i][last+1]=len;
}

int LIS(vector<int> arr, int n)
{
    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    return solution1(0,-1,arr,n,dp);
}

//iterative Approach

int LIS2(vector<int> vi,int n)
{
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    for(int i=n-1;i>=0;i--)
    {
        for(int last=i-1;last>=-1;last--)
        {
            int len=dp[i+1][last+1];
            if(last==-1||vi[last]<vi[i])
            len=max(len,1+dp[i+1][i+1]);

            dp[i][last+1]=len;
        }
    }
    return dp[0][0];
}

//Space Optimized Approach

int solution2(vector<int> vi, int n)
{
    vector<int> dp(n+1,0);
    for(int i=n-1;i>=0;i--)
    {
        vector<int> cur(n+1);
        for(int j=i-1;j>=-1;j--)
        {
            int len=dp[j+1];
            if(j==-1||vi[j]<vi[i])
            len=max(len,1+dp[i+1]);

            cur[j+1]=len;
        }
        dp=cur;
    }
    return dp[0];
}

//Binary Search Approach

int solution3(vector<int> arr,int n)
{
    vector<int> temp;
    temp.push_back(arr[0]);
    for(int i=1;i<n;i++)
    {
        if(arr[i]>temp.back())
        arr.push_back(arr[i]);
        else
        {
            int t=lower_bound(temp.begin(),temp.end(),arr[i])-temp.begin();
            arr[t]=arr[i];
        }
    }
    return temp.size();
}


int main()
{
    vector<int> arr={3,4,5,6,7,8,5,34,2,3,4,4};
    int n=arr.size();
    cout<<LIS(arr,n)<<endl;
    cout<<LIS2(arr,n);
}
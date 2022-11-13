#include <bits/stdc++.h>
using namespace std;

int dp[102][102];
int n;

int fun(vector<int> &arr, int i, int j, vector<int> &prefix)
{

    if (i > j)
        return 0;

    int size = j - i + 1;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (size == 1)
        return arr[i];
    else if (size == 2)
    {
        return dp[i][j] = arr[i] + arr[j];
    }

    else if (size == 3)
    {
        int a = arr[i] + arr[i + 1];
        int b = arr[i + 1] + arr[j];
        int mn, mx;
        if (a < b)
        {
            mn = a;
            mx = arr[j];
        }
        else
        {
            mn = b;
            mx = arr[i];
        }
        return dp[i][j] = 2 * mn + mx;
    }
    int ans = INT_MAX;
    for (int k = i + 1; k <= j; k++)
    {
        int a = 0, b = 0, tmp = 0;
        if (i != k - 1)
        {
            a = fun(arr, i, k - 1, prefix);
        }
        if (k != j)
        {
            b = fun(arr, k, j, prefix);
        }
        int sum = 0;
        if (i > 0)
            sum = prefix[j] - prefix[i - 1];
        else
            sum = prefix[j];
        ans = min(ans, a + b + sum);
    }
    return dp[i][j] = ans;
}

int findMinCost(vector<int> &arr, int N)
{
    memset(dp, -1, sizeof(dp));
    vector<int> prefix(N, 0);
    prefix[0] = arr[0];
    for (int i = 1; i < N; i++)
    {
        prefix[i] = prefix[i - 1] + arr[i];
    }
    n = N;
    return fun(arr, 0, n - 1, prefix);
}
//Calculating Fibonacci using dp


#include <bits/stdc++.h>
using namespace std;

int dp[10000];

int fibonacci(int n)
{
    if (n == 0 || n == 1)
        return n;
    if (dp[n] != -1)
        return dp[n];
    return dp[n] = fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cout << fibonacci(i) << endl;
}
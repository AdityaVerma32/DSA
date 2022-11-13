#include <bits/stdc++.h>
using namespace std;

int findMinCost(vector<int> &arr, int n)
{
    vector<int> temp= arr;
    sort(temp.begin(),temp.end());
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++)
    {
        mp[arr[i]]=i;
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int a=temp[i];
        auto it=mp.find(a);
        
    }
}
int main()
{
    vector<int> arr={1,3,7};
    cout<<findMinCost(arr,arr.size());
}
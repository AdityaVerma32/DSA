//finding longest substring with atmost k diffrfent letters

#include<bits/stdc++.h>
using namespace std;

int main()
{
    string str="aabcbcdbca";
    int k=2;
    unordered_map<int,int> mp;
    int ans=0;
    int i=0,j=0;
    int n=str.size();
    while(i<n)
    {
        mp[str[j]]++;
        j++;
        while(mp.size()>n)
        {
            mp[str[i]]--;
            if(mp[str[i]]==0)   mp.erase(str[i]);
            i++;
        }
        ans=max(ans,j-i);
    }
    cout<<ans;
}
// JJ has an array AA of length NN and an integer XX.JJ can perform the following operation at most once :

//     Select a subsequence of AA and add XX to all the elements of that subsequence.For example,
//     if A = [ 2, 1, 6, 3, 5 ] A = [ 2, 1, 6, 3, 5 ] and X = 7X = 7, we can select the subsequence[2, 3, 5][2, 3, 5] and add XX to all the elements.Now the array AA becomes[2 + 7, 1, 6, 3 + 7, 5 + 7] = [ 9, 1, 6, 10, 12 ][2 + 7, 1, 6, 3 + 7, 5 + 7] = [ 9, 1, 6, 10, 12 ].

#include <bits/stdc++.h>
using namespace std;

#define lli long long int
const lli N = 2e5;
vector<lli> vi(N);
lli temp[N][2];

int main()
{
    lli t;
    cin >> t;
    while (t--)
    {
        lli n, m;
        cin >> n >> m;
        for (lli i = 1; i <= n; ++i)
            cin >> vi[i];
        for (lli i = 2; i <= n; ++i)
        {
            temp[i][0] = max(temp[i - 1][0] + (vi[i - 1] ^ vi[i]), temp[i - 1][1] + ((vi[i - 1] + m) ^ vi[i]));
            temp[i][1] = max(temp[i - 1][0] + (vi[i - 1] ^ (vi[i] + m)), temp[i - 1][1] + ((vi[i - 1] + m) ^ (vi[i] + m)));
        }
        cout << max(temp[n][0], temp[n][1]) << endl;
    }
}

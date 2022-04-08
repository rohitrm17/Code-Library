// Find the no. in array which has single occurrence
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n , ans=0;
    cin >> n;
    vector<int> v(n);
    for(int i=0 ; i<n ; i++)
        cin >> v[i];
    for(int i=0 ; i<n ; i++)
        ans = ans ^ v[i];
    cout << ans << "\n";
    return 0;
}
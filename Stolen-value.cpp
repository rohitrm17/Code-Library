#include <bits/stdc++.h>

using namespace std;

void StolenValue(vector<int> v)
{
    int n=v.size();
    vector<int> dp(n , 0);
    dp[1] = v[1];
    for(int i=2 ; i<=n ; i++)
        dp[i] = max(dp[i-1] , dp[i-2]+v[i]);
    cout << "Max stolen value: " << dp[n-1];
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n+1 , 0);
    for(int i=1 ; i<=n ; i++)
        cin >> v[i];
    StolenValue(v);
    return 0;
}
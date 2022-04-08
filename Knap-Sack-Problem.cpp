#include <bits/stdc++.h>

using namespace std;

struct Item
{
    int weight;
    int value;
};

int main()
{
    int n , W;
    cin >> n;
    vector<Item> v(n);
    for(int i=0 ; i<n ; i++)
        cin >> v[i].weight >> v[i].value;
    
    cin >> W;

    vector<vector<int>> dp(n+1 , vector<int>(W+1 , 0));

    for(int i=1 ; i<=n ; i++)
        for(int j=1 ; j<=W ; j++)
            if(v[i-1].weight <= j)
            {
                dp[i][j] = max(v[i-1].value + dp[i-1][j-v[i-1].weight] , dp[i-1][j]);
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }

    cout << "DP table contains:\n";
    for(int i=0 ; i<=n ; i++)
    {
        for(int j=0 ; j<=W ; j++)
            cout << dp[i][j] << " ";
        cout << "\n";
    }

    cout << "\nMax value that can be stolen: " << dp[n][W];

    return 0;
}
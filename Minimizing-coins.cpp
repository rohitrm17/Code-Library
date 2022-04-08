// Getting the sum with min no. of coins 
#include <bits/stdc++.h>
 
using namespace std;

int minCoins(vector<int> coins , int sum)
{
    vector<int> dp(sum+1 , INT_MAX);
    dp[0] = 0;
    for(int i=1 , n=coins.size(); i<=sum ; i++)
        for(int j=0 ; j<n ; j++)
            if((i-coins[j]) >= 0)
                dp[i] = min(dp[i] , dp[i-coins[j]]+1);
    return dp[sum]; 
}

int main()
{
    int n , sum;
    cin >> n;
    vector<int> coins(n);
    for(int i=0 ; i<n ; i++)
        cin >> coins[i];
    cin >> sum;
    cout << minCoins(coins , sum) << "\n";
    return 0;
}
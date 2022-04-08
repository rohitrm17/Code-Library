// In how many ways a sum can be achived by throwing a dice
// Ex: sum can be 3 for (3) , (1,2) , (2,1) , (1,1,1) 
#include <bits/stdc++.h>

using namespace std;

int diceProblem(int sum)
{
    vector<int> dp(sum+1 , 0);
    dp[0] = 1;

    for(int i=1 ; i<=sum ; i++)
        for(int j=1 ; j<=6 && (i-j)>=0; j++)
            dp[i] = dp[i] + dp[i-j];

    return dp[sum];
}

int main()
{
    int sum;
    cin >> sum;
    cout << diceProblem(sum) << "\n";
    return 0;
}
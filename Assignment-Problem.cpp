#include <bits/stdc++.h>

using namespace std;

int count_set_bits(int no)
{
    int count = 0;
    while(no)
    {
        if(no & 1)
            count++;
        no = no >> 1;
    }
    return count;
}

int AssignmentProblem(int n , vector<vector<int>> cost)
{
    int p = pow(2 , n);
    int x;
    vector<int> dp(p);
    
    for(int i=0 ; i<p ; i++)
        dp[i] = INT_MAX;
    
    dp[0] = 0;

    for(int mask=0 ; mask<p ; mask++)
    {
        x = count_set_bits(mask);
        for(int j=0 ; j<n ; j++)
        {
            if((mask&(1<<j)) == 0)
            {
                dp[mask|(1<<j)] = min(dp[mask|(1<<j)] , dp[mask]+cost[x][j]);
            }
        }
    }
    
    return dp[p-1];
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> cost(n , vector<int>(n));
    for(int i=0 ; i<n ; i++)
        for(int j=0; j<n ; j++)
            cin >> cost[i][j];
    cout << "Min cost: " << AssignmentProblem(n , cost) ;
}
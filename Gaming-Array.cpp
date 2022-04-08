// In a game of 2 players
// P1 picks largest no. in array and removes all no. right to it including itself
// similarly P2 does the same thing 
// The player who makes the array empty wins.

#include <bits/stdc++.h>

#define ll long long int
#define BUFF_SIZE 1024
#define N 1000

using namespace std;

int solve(vector<int> v)
{
    int ans=0 , curMax=0;
    
    for(int i=0 ; i<v.size() ; i++)
    {
        if(curMax < v[i])
        {
            curMax = v[i];
            ans++;
        }
    }

    if(ans%2 == 0)
        return 2;

    return 1;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0 ; i<n ; i++)
        cin >> v[i];

    cout << solve(v) << endl;
    return 0;
}
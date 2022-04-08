// Find minimum no. of operations to be done on src to get destination string
// Ex: apiskal -> vishal 
// ans: 3
 
#include <bits/stdc++.h>

using namespace std;

int solve()
{
    string src , dest;
    cin >> src >> dest;
    
    int l1=src.size() , l2=dest.size();
    int a[l1+1][l2+1];

    for(int i=0 ; i<=l1 ; i++)
        a[i][0] = i;

    for(int i=0 ; i<=l2 ; i++)
        a[0][i] = i;

    for(int i=1 ; i<=l1 ; i++)
    {
        for(int j=1 ; j<=l2 ; j++)
            if(src[i-1] == dest[j-1])
                a[i][j] = a[i-1][j-1];
            else
                a[i][j] = min(a[i-1][j] , min(a[i][j-1] , a[i-1][j-1])) + 1;
    }

    return a[l1][l2];
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cout << solve() << endl;
    }
    return 0;
}
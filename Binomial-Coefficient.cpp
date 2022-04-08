// Find nCk

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n , k;
    cin >> n >> k;
    
    vector<vector<int>> c(n+1 , vector<int>(k+1 , 0));

    for(int i=0 ; i<n ; i++) 
    {
        for(int j=0 ; j<min(i,k) ; j++)
            if(i==j && j==0)
                c[i][j] = 1;
            else
                c[i][j] = c[i-1][j] + c[i-1][j-1];
    }

    for(int i=0 ; i<=n ; i++)
    {
        for(int j=0 ; j<=k ; j++)
            cout << c[i][j] << " ";
        cout<<"\n";
    }
    cout << n<<"C"<<k<<" = " << c[n][k];

    return 0;
}
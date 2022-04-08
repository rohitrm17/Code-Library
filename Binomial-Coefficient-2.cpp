// Find nCk

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n , k , r;
    cin >> n >> r;
    
    k = min(r , n-r);
    vector<int> c(k+1 , 0);

    c[0] = 1;

    for(int i=1 ; i<=n ; i++)
    {
        for(int j=min(i,k) ; j>0 ; j--)
            c[j] = c[j] + c[j-1];
    }

    cout << n<<"C"<<r<<" = " << c[k];

    return 0;
}